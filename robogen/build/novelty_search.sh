#!/bin/bash
echo "Starting novelty_search baseline experiments"
echo "------------------------------------"

echo "Running experiment set 9"
for x in {5..10}
do
	echo "Running experiment 9:($x/10)."
	./robogen-server 8009 &>/dev/null &
	./robogen-evolver $RANDOM noveltyResults/baseline/Experiment9/novelty_output9 ../projectSimulations/novelty_search/evolConf9.txt --save-all
	echo "Experiment 9:($x/10) finished."
done
echo "Experiment set 9 finished..."

