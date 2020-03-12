#!/bin/bash

set -eu

if [ ${#} -ne 1 ]; then
    echo "Usage: ./localtest.sh <a ~ f>"
    exit 1
fi

readonly base_path=$(cd $(dirname ${0}); pwd)
readonly problems_dir="${base_path}/problems"
readonly p_name=${1}
readonly p_path="${problems_dir}/${p_name}.cpp"
readonly p_out="${problems_dir}/a.out"

g++ -Wall -std=c++17 -g ${p_path} -o ${p_out}

echo "Info: input test case."
${p_out}
