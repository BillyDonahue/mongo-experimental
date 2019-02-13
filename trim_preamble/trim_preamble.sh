#!/bin/bash
# trim_preamble.sh [filename ...]

# For each filename:
#   Delete all leading blank lines.
#   Delete any leading comment that contains just the filename and punctuation.
#   Repeat until no change.




function subst () {
    local f
    for f in "$@"; do
        ./trim_preamble.py "$f"
    done
}

files=(
    src/mongo/db/curop.h
    src/mongo/db/service_context_devnull_test_fixture.h
    src/mongo/db/lasterror.h
    src/mongo/db/mongod_options.h
    src/mongo/db/service_liaison_mock.h
    src/mongo/db/run_op_kill_cursors.h
    src/mongo/db/free_mon/free_mon_network.h
    src/mongo/db/free_mon/free_mon_op_observer.h
)
files=($(find src/mongo -name '*.cpp' -o -name '*.h' | grep -v gotools))
# for f in "${files[@]}"; do echo $f; done
subst "${files[@]}"
