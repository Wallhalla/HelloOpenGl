#!/bin/bash

if ! which premake5 >/dev/null 2>&1; then
  echo "$0: premake5 is missing. Please install it." >&2
  exit 1
fi

premake5 gmake2

echo "Done the following commands are used for building:"
echo "- DEBUG: make"
echo "- RELEASE: make Application_config=release"

