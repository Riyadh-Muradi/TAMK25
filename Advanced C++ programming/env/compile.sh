#!/usr/bin/env bash
set -euo pipefail

if [ "$#" -lt 1 ]; then
  echo "Usage: ./compile.sh <file1.cpp> [file2.cpp ...] [-o output]"
  exit 1
fi

SOURCES=()
OUTPUT=""

while [[ "$#" -gt 0 ]]; do
  case "$1" in
    -o)
      OUTPUT="$2"
      shift 2
      ;;
    *)
      SOURCES+=("$1")
      shift
      ;;
  esac
done

if [ "${#SOURCES[@]}" -eq 0 ]; then
  echo "Error: no source files provided"
  exit 1
fi

if [ -z "$OUTPUT" ]; then
  OUTPUT="${SOURCES[0]%.cpp}"
fi

clang++ -std=c++20 -Wall -Wextra "${SOURCES[@]}" -o "$OUTPUT"
