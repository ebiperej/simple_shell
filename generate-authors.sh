#!/bin/bash
#source: https://github.com/docker/docker/blob/master/hack/generate-authors.sh
# This file lists all individuals having contributed content to the repository.
set -e

#cd "$(dirname "$(readlink -f "$BASH_SOURCE")")/.."

# see also ".mailmap" for how email addresses and names are deduplicated

{
	cat <<-'EOH'
	EOH
	echo
	git log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf
} > AUTHORS
