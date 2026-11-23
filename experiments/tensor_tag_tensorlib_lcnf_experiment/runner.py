from pathlib import Path
import os, subprocess, sys

THESIS = Path('/Users/handelmac/handelmac_house/uml_handel/thesis')
HERE = THESIS / 'experiments' / 'tensor_tag_tensorlib_lcnf_experiment'
TENSORLIB = THESIS / 'external' / 'TensorLib'

# Prefer a thesis-wide Lake project if available; otherwise TensorLib's own.
projects = [THESIS]
projects = [p for p in projects if any((p / f).exists() for f in ('lakefile.toml','lakefile.lean'))]
if not projects:
    print('ERROR: No Lake project found in thesis root or external/TensorLib.')
    sys.exit(1)

# Compile from a Lake root so its dependency environment is available.
env = os.environ.copy()
env['LEAN_PATH'] = str(HERE) + os.pathsep + env.get('LEAN_PATH','')

def run(project, *args):
    print('==', ' '.join(args), flush=True)
    return subprocess.run(args, cwd=project, env=env).returncode

for project in projects:
    print('== Lake project ==', project, flush=True)
    if run(project, 'lake','env','lean','--version'): continue
    if run(project, 'lake','env','lean','-o',str(HERE/'Probe.olean'),str(HERE/'Probe.lean')): continue
    if run(project, 'lake','env','lean','-c',str(HERE/'Main.c'),str(HERE/'Main.lean')): continue
    if run(project, 'lake','env','lean','--run',str(HERE/'Main.lean')): sys.exit(1)
    print('== SUCCESS: inspect [CALL/EARLY], [CALL/LATE], and [LIT/*] above ==')
    sys.exit(0)
print('ERROR: Could not compile TensorLib experiment under available Lake projects.')
sys.exit(1)
