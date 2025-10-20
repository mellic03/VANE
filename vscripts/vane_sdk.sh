#!/bin/bash

cd vane_sdk

rm -rf ./vane_sdk
mkdir -p vane_sdk

cp -R sdk/* vane_sdk/
cp -R gamefolder vane_sdk/
# tar -cf vane_sdk/gamefolder.tar -C gamefolder .

cd ../
rm -rf ../build/vane_sdk
mv  ./vane_sdk/vane_sdk ../build/vane_sdk
cd ../

mv  build/lib build/vane_sdk/lib
cp -R include build/vane_sdk

