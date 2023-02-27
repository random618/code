#!/bin/bash
name=$1
if [[ $name == "" ]]; then
    echo "usage: ./copy.sh name"
    exit 0
fi
cp ./src/example.cc ./src/$name

function trans() {
    input=$1
    pre=$(echo $input | awk -F '.cc' '{print $1}')
    arr=$(echo $pre | awk '{len=split($0, arr, "_"); for(i=1;i<=len;i++){print arr[i]}}')
    res=""
    for ele in $arr
    do
        up=$(toFirstLetterUpper $ele)
        res=$res$up
    done
    echo $res
}

function toFirstLetterUpper(){
  str=$1
  firstLetter=${str:0:1}
  otherLetter=${str:1}
  firstLetter=$(echo $firstLetter | tr '[a-z]' '[A-Z]')
  result=$firstLetter$otherLetter
  echo $result
}

output=$(trans $name)
echo $output

sed -i s"/Example/${output}/g" ./src/$name
