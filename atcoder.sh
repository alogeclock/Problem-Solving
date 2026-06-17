#!/bin/bash
set -e

BASE="./atcoder"
TPL="./template.cpp"
CXX=${CXX:-g++}
FLAGS="-std=c++17 -O2 -pipe -Wall -Wextra"

check_oj() { command -v oj >/dev/null || { echo "[ERROR] Install oj: pip install online-judge-tools"; exit 1; }; }

CMD=$1
C_IN=$2
P_IN=$3

if [ "$CMD" = "-c" ] || [ "$CMD" = "--copy" ]; then
    [ -z "$C_IN" ] && { echo "Usage: $0 -c <contest>"; exit 1; }
    check_oj; [ ! -f "$TPL" ] && { echo "[ERROR] No $TPL"; exit 1; }

    CDIR=$(echo "$C_IN" | tr '[:upper:]' '[:lower:]')
    CID=$(echo "$CDIR" | sed 's/-//g')

    for P in A B C D E F; do
        p=$(echo "$P" | tr '[:upper:]' '[:lower:]')
        DIR="$BASE/$CDIR/$P"
        
        mkdir -p "$DIR"
        [ ! -f "$DIR/$P.cpp" ] && cp "$TPL" "$DIR/$P.cpp"
        oj d "https://atcoder.jp/contests/$CID/tasks/${CID}_${p}" -d "$DIR/test" || true
    done
    echo "[OK] Setup complete: $CDIR"

elif [ "$CMD" = "-t" ] || [ "$CMD" = "--testcase" ]; then
    [ -z "$P_IN" ] && { echo "Usage: $0 -t <contest> <problem>"; exit 1; }
    check_oj
    
    CDIR=$(echo "$C_IN" | tr '[:upper:]' '[:lower:]')
    CID=$(echo "$CDIR" | sed 's/-//g')
    P=$(echo "$P_IN" | tr '[:lower:]' '[:upper:]')
    p=$(echo "$P" | tr '[:upper:]' '[:lower:]')
    DIR="$BASE/$CDIR/$P"

    [ ! -f "$DIR/$P.cpp" ] && { echo "[ERROR] No source file: $DIR/$P.cpp"; exit 1; }
    [ ! -d "$DIR/test" ] && oj d "https://atcoder.jp/contests/$CID/tasks/${CID}_${p}" -d "$DIR/test"

    echo "[BUILD] Compiling $P.cpp..."
    "$CXX" $FLAGS "$DIR/$P.cpp" -o "$DIR/$P"
    
    echo "[TEST] Running tests..."
    oj t -c "$DIR/$P" -d "$DIR/test"

else
    echo "Usage: $0 -c <contest> | $0 -t <contest> <problem>"
fi