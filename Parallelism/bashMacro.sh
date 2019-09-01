# 0.- Guardamos la fecha y hora de inicio del macro.
start_date=$(date +%x) && start_time=$(date +%X)


# 1.- Definir los parámetros de entrada.

# Ruta al Macro Maestro (RutaMM).
RutaMM=/home/saksevul/T/Parallelism/rootMacro.C
# previo Algoritmo de Reconstrucción de Jets (pARJ).
iARJ=ak5
  # final Algoritmo de Reconstrucción de Jets (iARJ).
  pARJ=$iARJ


# 2.- Realizar ciclo for para considerar los distintos datos.

# Ciclo for sobre Algoritmo de Reconstrucción de Jets (ARJ).
for ARJ in ak5 ak7 kt4 kt6
do
  # Modificamos el MM para utilizar el ARJ actual.
  sed -i "s/$pARJ/$ARJ/g" $RutaMM
  # Correr el Macro Maestro (MM). (Sin mensajes de error).
  root -l -q $RutaMM # 2> /dev/null
  # Redefinios pARJ para el siguiente ciclo for.
  pARJ=$ARJ
done  # Fin del ciclo for para ARJ.


# 3.- Regresar el Macro Maestro (MM) a su estado inicial.
sed -i "s/$pARJ/$iARJ/g" $RutaMM


# 4.- Mostrar la fecha y hora de inicio y término de este macro.
printf "\n\n Inició  el  $start_date, a las  $start_time.\n\n Terminó el  $(date +%x), a las  $(date +%X).\n\n"


# 5.- Eliminar todas las variables utilizadas.
exec bash
