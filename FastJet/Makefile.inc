# PYTHIA configuration file.
# Generated on jue mar 14 20:33:01 CST 2019 with the user supplied options:
# --with-fastjet3=/home/saksevul/fastjet332
# --with-root=/home/saksevul/root61406

# Install directory prefixes.
PREFIX_BIN=/home/saksevul/pythia8240/bin
PREFIX_INCLUDE=/home/saksevul/pythia8240/include
PREFIX_LIB=/home/saksevul/pythia8240/lib
PREFIX_SHARE=/home/saksevul/pythia8240/share/Pythia8

# Compilation flags (see ./configure --help for further documentation).
ENABLE_SHARED=false
CXX=g++
CXX_COMMON=-O2  -pedantic -W -Wall -Wshadow -fPIC
CXX_SHARED=-shared
CXX_SONAME=-Wl,-soname,
LIB_SUFFIX=.so

# EVTGEN configuration.
EVTGEN_USE=false
EVTGEN_BIN=
EVTGEN_INCLUDE=
EVTGEN_LIB=

# FASTJET3 configuration.
FASTJET3_USE=true
FASTJET3_BIN=/home/saksevul/fastjet322/bin
FASTJET3_INCLUDE=/home/saksevul/fastjet322/include
FASTJET3_LIB=/home/saksevul/fastjet322/lib

# HEPMC2 configuration.
HEPMC2_USE=false
HEPMC2_BIN=
HEPMC2_INCLUDE=
HEPMC2_LIB=

# HEPMC3 configuration.
HEPMC3_USE=false
HEPMC3_BIN=
HEPMC3_INCLUDE=
HEPMC3_LIB=

# LHAPDF5 configuration.
LHAPDF5_USE=false
LHAPDF5_BIN=
LHAPDF5_INCLUDE=
LHAPDF5_LIB=

# LHAPDF6 configuration.
LHAPDF6_USE=false
LHAPDF6_BIN=
LHAPDF6_INCLUDE=
LHAPDF6_LIB=

# POWHEG configuration.
POWHEG_USE=false
POWHEG_BIN=
POWHEG_INCLUDE=
POWHEG_LIB=

# PROMC configuration.
PROMC_USE=false
PROMC_BIN=
PROMC_INCLUDE=
PROMC_LIB=

# ROOT configuration.
ROOT_USE=true
ROOT_BIN=/home/saksevul/root61406/bin/
ROOT_INCLUDE=/home/saksevul/root61406/include	# Directorio faltante.
ROOT_LIBS=-L/home/saksevul/root61406/lib -lGui -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTDataFrame -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -pthread -lm -ldl -rdynamic
#CXX_ROOT=-O2  -W -Wall -Wshadow -fPIC -pthread -std=c++11 -m64 -I/home/saksevul/root61406/include

# GZIP configuration.
GZIP_USE=false
GZIP_BIN=
GZIP_INCLUDE=
GZIP_LIB=

# BOOST configuration.
BOOST_USE=false
BOOST_BIN=
BOOST_INCLUDE=
BOOST_LIB=

# PYTHON configuration.
PYTHON_USE=false
PYTHON_BIN=
PYTHON_INCLUDE=
PYTHON_LIB=
