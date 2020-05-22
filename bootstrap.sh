#!/bin/sh

die() {
	echo "$@" 1>&2; exit 1
}

src_dir=`cd "\`dirname \"$0\"\`";pwd`

generator="";
toolchain=true;

while test $# != 0; do
	case "$1" in
		--ninja) generator="-G Ninja" ;;
		*) die "Unknown option: $1" ;;
	esac
	shift
done

buid_dir="${src_dir}/build"
if [ -d "${build_dir}" ]; then
	die "found direcotry ${src_dir}/build. Plese remmove it before bootstrap"
fi

toolchain_file="";
if ${toolchain}; then
	toolchain_file="${src_dir}/toolchain/ToolChain.cmake"
	if [ ! -f "${toolchain_file}" ]; then
		die "Toolchain file ${toolchain_file} missiong . Please verify your directory"
	fi
	toolchian_file="-DCMAKE_TOOLCHAIN_FILE=${toolchain_file}"
fi

echo "bootstraping ...."
cmake -S ${src_dir} -B ${build_dir} ${generator} ${toolchain_file}




