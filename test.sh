#!/bin/bash

set -eu

if [ ${#} -ne 1 ]; then
    echo "Usage: ./test.sh <a ~ f>"
    exit 1
fi

readonly base_path=$(cd $(dirname ${0}); pwd)
readonly problems_dir="${base_path}/problems"
readonly p_name=${1}
readonly p_path="${problems_dir}/${p_name}.cpp"
readonly test_dir="${problems_dir}/${p_name}-test"

if [ ! -d ${test_dir} ]; then
    read -p "Info: input problem url. > " url
    mkdir -p ${test_dir}
    cd ${test_dir}
    oj dl ${url}
fi

g++ -Wall -std=c++17 -g ${p_path} -o "${test_dir}/a.out"

cd ${test_dir}
oj test
