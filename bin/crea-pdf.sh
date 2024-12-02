#/bin/bash

BASE_DIR=~/Developer/Chi++
BIN_DIR=${BASE_DIR}/bin
MAN_DIR=${BASE_DIR}/docs/man
OUT_DIR=${BASE_DIR}/_book

MAN_FILE=${OUT_DIR}/man-file.txt
CSS_FILE=${BASE_DIR}/_sass/pdf.css
YML_FILE=${BASE_DIR}/_data/pdf.yml

FILENAME="chi-plus-plus"
FILE_NEW=$FILENAME".md"
FILE_OLD=$FILENAME".old"
VERSIONE=`cat VERSION`
DATA="$(date +'%d-%m-%Y')"

cd ${MAN_DIR}

echo "Genero il file PDF completo"
pandoc  --verbose                 						\
				--css ${CSS_FILE}    				 					\
        --pdf-engine=wkhtmltopdf  					  \
				--pdf-engine-opt="--print-media-type" \
				--pdf-engine-opt="--title" 					  --pdf-engine-opt="C'hi++, il senso della vita" \
        --pdf-engine-opt="--header-left"      --pdf-engine-opt="C'hi++, il senso della vita è il debug"\
        --pdf-engine-opt="--header-right"     --pdf-engine-opt="[page] di [topage]" \
        --pdf-engine-opt="--header-font-name" --pdf-engine-opt="Bookerly"          \
        --pdf-engine-opt="--header-font-size" --pdf-engine-opt="10"                 \
        --pdf-engine-opt="--header-spacing"   --pdf-engine-opt="10"                 \
        --pdf-engine-opt="--footer-left"      --pdf-engine-opt="Carlo Simonelli"    \
        --pdf-engine-opt="--footer-right"     --pdf-engine-opt="[date]"             \
        --pdf-engine-opt="--footer-font-name" --pdf-engine-opt="Bookerly"          \
        --pdf-engine-opt="--footer-font-size" --pdf-engine-opt="10"                 \
        --pdf-engine-opt="--footer-spacing"   --pdf-engine-opt="10"                 \
        --pdf-engine-opt="--margin-top"       --pdf-engine-opt="3cm"                \
        --pdf-engine-opt="--margin-right"     --pdf-engine-opt="2cm"                \
        --pdf-engine-opt="--margin-bottom"    --pdf-engine-opt="3cm"                \
        --pdf-engine-opt="--margin-left"      --pdf-engine-opt="3cm"                \
				--pdf-engine-opt="--page-size"        --pdf-engine-opt="A4"                 \
				--pdf-engine-opt='cover'              --pdf-engine-opt="${OUT_DIR}/copertina.html" \
        $(<${MAN_FILE})             \
				-o ${OUT_DIR}/$FILENAME.pdf

# rimuove i file .DS_Store"
find . -type f -name .DS_Store -exec rm {} \;
