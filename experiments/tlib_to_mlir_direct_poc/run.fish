#!/usr/bin/env fish

# THIS IS THE FILE YOU RUN.
#
# PURPOSE: Start the POC and keep diagnostic logs for every run.
#
# It does NOT contain the matrix multiplication or the compiler pass.
# Those live in Main.lean and LtomPocSupport.lean.
#
# Think of the pipeline like this:
# run.fish
#   -> asks Lake to prepare the Lean project's environment
#   -> starts compile_in_project.fish
#   -> that script compiles and runs the Lean files
#   -> if a step fails, copy_diagnostics.fish copies logs using pbcopy


# =============================================================
# PART 1: Find the project folders.
# =============================================================

# We need the absolute path to this script's folder, because the user
# might launch run.fish from anywhere in the terminal.
set -l poc_directory (cd (dirname (status --current-filename)); and pwd)

# The thesis project's Lake configuration is two folders above this one.
# Lake needs to be started there to find the correct dependencies.
set -l thesis_root (cd "$poc_directory/../.."; and pwd)


# =============================================================
# PART 2: Make a NEW log folder for this run.
# =============================================================

# We do this so a new failure never overwrites an older error log.
set -l log_parent "$poc_directory/artifacts/logs"
mkdir -p "$log_parent"; or exit 1

# Timestamp makes the folder recognizable; mktemp adds random characters
# so simultaneous runs still get different folders.
set -l timestamp (date '+%Y-%m-%d_%H-%M-%S')
set -l log_directory (mktemp -d "$log_parent/$timestamp.XXXXXX")
if test -z "$log_directory"
    echo "ERROR: Could not create a log directory."
    exit 1
end


# =============================================================
# PART 3: Start compilation and execution.
# =============================================================

cd "$thesis_root"; or exit 1

echo "Starting direct Lean-to-MLIR POC"
echo "Logs: $log_directory"

# WHAT IS LAKE DOING HERE?
# Lake is Lean's project/build tool. It knows where project libraries live.
# `lake env fish some_script.fish` launches Fish with those libraries
# available to Lean, then lets that Fish script run the compiler commands.
#
# `compile_in_project.fish` exists so the three actual Lean operations
# are easy to read in one place. There is no `lake env env` command.
#
# The final `> ... 2>&1` saves both normal messages AND errors in lake.log.
if not lake env fish "$poc_directory/compile_in_project.fish" \
    "$poc_directory" "$log_directory" > "$log_directory/lake.log" 2>&1

    echo "ERROR: The POC failed."
    cat "$log_directory/lake.log"

    # Collect every available log into one text report and the clipboard.
    fish "$poc_directory/copy_diagnostics.fish" "$log_directory"
    exit 1
end


# =============================================================
# PART 4: Show the successful result.
# =============================================================

# The inner script already tested compilation and real matrix execution.
cat "$log_directory/lake.log"
echo "StableHLO: $poc_directory/artifacts/matmul.mlir"
echo "Logs: $log_directory"
