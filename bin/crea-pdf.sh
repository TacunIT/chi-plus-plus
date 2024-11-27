#/bin/bash

BASE_DIR=~/Developer/Chi++
BIN_DIR=${BASE_DIR}/bin
MAN_DIR=${BASE_DIR}/docs/man
OUT_DIR=${BASE_DIR}/_book

MAN_FILE=${BIN_DIR}/man-file.txt
CSS_FILE=/assets/css/pdf.css

FILENAME="chi-plus-plus"
FILE_NEW=$FILENAME".md"
FILE_OLD=$FILENAME".old"
VERSIONE=`cat VERSION`
DATA="$(date +'%d-%m-%Y')"

cd ${MAN_DIR}

echo "Genero il file PDF completo"
pandoc  --verbose                            \
        --pdf-engine=wkhtmltopdf             \
        --pdf-engine-opt="--header-left"      --pdf-engine-opt="[title]"            \
        --pdf-engine-opt="--header-right"     --pdf-engine-opt="[page] of [topage]" \
        --pdf-engine-opt="--header-font-name" --pdf-engine-opt="Bookerly"           \
        --pdf-engine-opt="--header-font-size" --pdf-engine-opt="11"                 \
        --pdf-engine-opt="--header-spacing"   --pdf-engine-opt="10"                 \
        --pdf-engine-opt="--footer-left"      --pdf-engine-opt="Carlo Simonelli"    \
        --pdf-engine-opt="--footer-right"     --pdf-engine-opt="[date]" \
        --pdf-engine-opt="--footer-font-name" --pdf-engine-opt="Bookerly"           \
        --pdf-engine-opt="--footer-font-size" --pdf-engine-opt="11"                 \
        --pdf-engine-opt="--footer-spacing"   --pdf-engine-opt="10"                 \
        --pdf-engine-opt="--margin-top"       --pdf-engine-opt="3cm"                \
        --pdf-engine-opt="--margin-right"     --pdf-engine-opt="2cm"                \
        --pdf-engine-opt="--margin-bottom"    --pdf-engine-opt="3cm"                \
        --pdf-engine-opt="--margin-left"      --pdf-engine-opt="3cm"                \
				--pdf-engine-opt="--page-size"        --pdf-engine-opt="A4"                 \
        --css ./css/mammifero.css    \
        $(<${MAN_FILE})              \
        ./data/metadati.yml          \
        -o ./$FILENAME.pdf

prima=$(cat PAROLE)
dopo=$(wc -w chi-plus-plus.md | awk '{print $1}' | tee PAROLE )
diff=$((dopo-prima))
echo "Parole aggiunte: $diff"
echo "Parole totali  : $dopo"
echo "Pagine stimate : $((dopo / 300))"
echo $(wc -lwm chi-plus-plus.md | awk '{print $1, $2, $3}' )

# rimuove i file .DS_Store"
find . -type f -name .DS_Store -exec rm {} \;
