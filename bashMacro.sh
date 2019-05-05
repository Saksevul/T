# Este es un Macro para correr análisis, Simulacion y comparacion.

parallel root -q -l ::: OpenData/Analisis.C Parallelism/rootMacro.C > Output.txt 2> /dev/null
