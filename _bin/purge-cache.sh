#!/bin/zsh
#
#   Il comando richiede la "Zone ID" nella URL e la API key negli header.
#

curl -X POST "https://api.cloudflare.com/client/v4/zones/f6bafdeec38ea3d4d67c0c073a702aa6/purge_cache" \
	-H "X-Auth-Email: cloudflare@canaro.net" \
	-H "X-Auth-Key: $(< ~/.ssh/cloudflare-api.key) " \
	-H "Content-Type: application/json" \
	--data '{"purge_everything":true}'
