#!/bin/bash

script_dir=$( cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
export LD_LIBRARY_PATH="$script_dir/bin"

alias vpart='"$script_dir"/bin/vpart'
alias vpkg='"$script_dir"/bin/vpkg'
alias vukg='"$script_dir"/bin/vukg'
