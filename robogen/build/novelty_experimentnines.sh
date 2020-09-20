echo "Running experiment set 9 complexityCost"
for x in {1..10}
do
	echo "Running experiment 9:($x/10). cc"
	./robogen-server 8009 &>/dev/null &
	./robogen-evolver $RANDOM noveltyResults/complexityCost/Experiment9/novelty_output9 ../projectSimulations/novelty_search/evolConf9.txt --save-all --complexity-cost
	echo "Experiment 9:($x/10) finished. cc"
done
echo "Experiment set 9 complexityCost finished..."
echo "Running experiment set 9 baseline"
for x in {1..10}
do
	echo "Running experiment 9:($x/10). b"
	./robogen-server 8009 &>/dev/null &
	./robogen-evolver $RANDOM noveltyResults/complexityCost/Experiment9/novelty_output9 ../projectSimulations/novelty_search/evolConf9.txt --save-all
	echo "Experiment 9:($x/10) finished. b"
done
echo "Experiment set 9 baseline finished..."