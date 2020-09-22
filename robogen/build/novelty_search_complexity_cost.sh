#!/bin/bash
echo "Starting novelty_search complexity cost experiments"
echo "------------------------------------"
echo "running experiment set 7"
for x in {4..10}
do
	echo "Running experiment 7:($x/10)."
	./robogen-server 8007 &>/dev/null &
	./robogen-evolver $RANDOM noveltyResults/complexityCost/Experiment7/novelty_output7 ../projectSimulations/novelty_search/evolConf7.txt --save-all --complexity-cost
	echo "Experiment 7:($x/10) finished."
done