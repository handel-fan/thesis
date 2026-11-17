#!/usr/bin/env fish

# THIS FILE IS USED WHEN SOMETHING FAILS.
#
# PURPOSE: Take all the logs from one POC run, put them into ONE text file,
# and copy the whole thing to the macOS clipboard (pbcopy).
#
# run.fish calls it automatically on failure.
# You can also run it yourself to re-copy the most recent run's logs.


# =============================================================
# PART 1: Decide which run's logs to collect.
# =============================================================

set -l poc_directory (cd (dirname (status --current-filename)); and pwd)
set -l log_directory $argv[1]

# If no folder was specified, find the newest run's log directory.
# We can do this because their names start with sortable timestamps.
if test -z "$log_directory"
    set log_directory (find "$poc_directory/artifacts/logs" \
        -mindepth 1 -maxdepth 1 -type d | sort | tail -n 1)
end

if test -z "$log_directory"; or not test -d "$log_directory"
    echo "ERROR: No POC logs were found."
    exit 1
end


# =============================================================
# PART 2: Combine the logs into a single diagnostic report.
# =============================================================

set -l diagnostic_file "$log_directory/diagnostics.txt"

# Fish's `begin ... end > file` lets us save the output of a WHOLE
# group of commands into one file. The contents include:
# - tool versions (useful for Lean API/version differences), and
# - every log that exists for this run.
begin
    echo "DIRECT POC DIAGNOSTICS"
    echo "Log directory: $log_directory"
    echo "Current directory: "(pwd)
    echo
    echo "LEAN VERSION"
    lean --version 2>&1
    echo
    echo "LAKE VERSION"
    lake --version 2>&1

    # A failed run might not have reached the later steps yet.
    # For missing logs, record that they were never created.
    for name in lake support compile runtime
        echo
        echo "================ $name.log ================"
        if test -f "$log_directory/$name.log"
            cat "$log_directory/$name.log"
        else
            echo "(not created by this run)"
        end
    end
end > "$diagnostic_file"


# =============================================================
# PART 3: Copy the report to the clipboard.
# =============================================================

# pbcopy is the standard macOS program that copies text to the clipboard.
if command -sq pbcopy
    pbcopy < "$diagnostic_file"
    echo "Diagnostics copied to clipboard: $diagnostic_file"
else
    # Even without pbcopy, the text file still exists and is preserved.
    echo "Diagnostics saved (clipboard unavailable): $diagnostic_file"
end
