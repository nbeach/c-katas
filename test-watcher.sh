#! /bin/bash

function block_for_change {
  inotifywait --quiet -r -e modify,move,create,delete test src
}

function run_tests {
  printf '\n'
  make --silent check
  printf '\n'
}

run_tests
while block_for_change; do
  run_tests
done
