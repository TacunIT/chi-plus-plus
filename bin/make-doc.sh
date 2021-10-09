#!/bin/bash

BASE_DIR=~/Developer/Chi++ 
MAN_DIR=${BASE_DIR}/docs/man
MAN_FILE=${BASE_DIR}/bin/man-file.txt
CSS_FILE=${MAN_DIR}/assets/css/pdf.cs
OUT_FILE=${MAN_DIR}/merged.html

cd ${MAN_DIR}

echo "pandoc $(<${MAN_FILE}) -s -t html --toc -c ${CSS_FILE} -o ${OUT_FILE}"
pandoc $(<${MAN_FILE}) -s -t html --toc -c ${CSS_FILE} -o ${OUT_FILE}
