#! /bin/bash

passedNum=0
failedNum=0

# Test case 1: load the XML file and write 
rm -rf ./output_ft.html
../../xml2html ../unit/cd_catalog.xml ./output_ft.html

retVal=$?

if [ $retVal -ne 0 ]; then
    echo "Test case 1 failed. Return value "$retVal
    ((failedNum = failedNum + 1))
else
    rm -rf ./output_ft.html
    echo "Test case 1 passed."
    ((passedNum = passedNum + 1))   
fi

# Test case 2: missing paramters 
../../xml2html 

retVal=$?

if [ $retVal -ne 1 ]; then
    echo "Test case 2 failed. Return value "$retVal
    ((failedNum = failedNum + 1))
else
    echo "Test case 2 passed."
    ((passedNum = passedNum + 1))
fi


# Test case 3: non existing xml file
../../xml2html ./non-existing.xml ./non-existing.html

retVal=$?

if [ $retVal -ne 3 ]; then
    echo "Test case 3 failed. Return value "$retVal
    ((failedNum = failedNum + 1))
else
    echo "Test case 3 passed."
    ((passedNum = passedNum + 1))
fi

# Test case 4: non existing html file path
../../xml2html ../unit/cd_catalog.xml ./non-this-path/output_ft.html

retVal=$?

if [ $retVal -ne 4 ]; then
    echo "Test case 4 failed. Return value "$retVal
    ((failedNum = failedNum + 1))
else
    echo "Test case 4 passed."
    ((passedNum = passedNum + 1))
fi

echo "================================================================="
echo $passedNum" test case(s) passed. " $failedNum" test case(s) failed."
