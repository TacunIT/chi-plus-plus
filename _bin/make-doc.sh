#!/bin/bash

BASE_DIR=~/Developer/Chi++ 
MAN_DIR=${BASE_DIR}/docs/man
MAN_FILE=${BASE_DIR}/_bin/man-file.txt
CSS_FILE=/assets/css/pdf.css
OUT_DIR=${BASE_DIR}/_man
OUT_FILE=${OUT_DIR}/pdf.html
TEMPLATE=${BASE_DIR}/_layouts/pdf.html

cd ${MAN_DIR}

echo "pandoc $(<${MAN_FILE}) -s -t html --toc -c ${CSS_FILE} -o ${OUT_FILE} --template=${TEMPLATE} "
pandoc $(<${MAN_FILE}) -s -t html --toc -c ${CSS_FILE} -o ${OUT_FILE} --template=${TEMPLATE} --section-divs
