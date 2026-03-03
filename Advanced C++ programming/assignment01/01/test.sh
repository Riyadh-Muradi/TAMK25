#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
tmp_dir="$(mktemp -d)"
trap 'rm -rf "$tmp_dir"' EXIT

exe="$tmp_dir/hello_world"

clang++ -std=c++20 -Wall -Wextra -Werror "$script_dir/main.cpp" -o "$exe"

output="$($exe)"

if [[ "$output" != "hello world" ]]; then
  echo "Expected output: hello world"
  echo "Actual output: $output"
  exit 1
fi

if [[ ! -f "$script_dir/screenshot.png" ]]; then
  echo "Missing screenshot.png in $(pwd)"
  exit 1
fi

echo "Test OK!"
