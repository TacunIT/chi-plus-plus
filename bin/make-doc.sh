#!/bin/bash

BASE_DIR=~/Developer/Chi++ 
MAN_DIR=${BASE_DIR}/docs/man
MAN_FILE=${BASE_DIR}/bin/man-file.txt

cd ${MAN_DIR}

pandoc $(<../../bin/man-file.txt) -s -t html --toc -c ../assets/css/pdf.css -o merged.html
