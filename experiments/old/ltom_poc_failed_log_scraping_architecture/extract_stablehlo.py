from pathlib import Path
import sys

# PURPOSE:
# Find the StableHLO printed by our custom compiler pass
# and save it into its own file.
#
# The Fish script gives us two filenames:
#   1. The compiler log to read.
#   2. The .mlir file to create.

compiler_log = Path(sys.argv[1])
output_file = Path(sys.argv[2])


# Read the compiler's messages, one line at a time.
log_lines = compiler_log.read_text().splitlines()

stablehlo = None

for line in log_lines:

    # Our compiler pass marks diagnostic messages
    # with [POC]. Display those messages.
    if "[POC]" in line:
        print(line)

    # Our compiler pass marks generated StableHLO
    # with [SHLO].
    #
    # For example:
    # [SHLO] module {@@NL@@ func.func ... @@NL@@}

    marker = "[SHLO] "

    # Only take the first StableHLO output we find.
    if marker in line and stablehlo is None:

        # Remove the [SHLO] marker.
        stablehlo = line.split(marker, 1)[1]

        # Our compiler pass replaces newlines with @@NL@@
        # so the entire StableHLO program fits on one log line.
        #
        # Restore those newlines to make the code readable.
        stablehlo = stablehlo.replace("@@NL@@", "\n")


# If no StableHLO appeared, the test failed.
if stablehlo is None:
    sys.exit("FAIL: The compiler did not emit StableHLO")


# Save the extracted StableHLO as an MLIR text file.
output_file.write_text(stablehlo + "\n")

# Display the result.
print("\n--- Generated StableHLO ---")
print(stablehlo)
