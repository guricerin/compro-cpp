#!/bin/bash

set -eu

readonly base_path=$(cd $(dirname ${0}); pwd)
readonly problems_dir="${base_path}/problems"
readonly temp_dir="${base_path}/template"

if [ -d ${problems_dir} ]; then
    read -p "Info: ${problems_dir} is already exists. Remake that? [y/n] > " res
    if [ ${res} != "y" ]; then
        echo "Info: stop process."
        exit 1
    fi
fi

rm -rf ${problems_dir}
mkdir -p ${problems_dir}

for p_name in {a..f}; do
    cp ${temp_dir}/main.cpp ${problems_dir}/${p_name}.cpp
done

echo "Making src/bin dir have done. Go For It!"