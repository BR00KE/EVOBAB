echo "Finishing last experiment for objective search with complexity cost"

echo "Running experiment set 11"
for x in {5..10}
do
	num=$((11 + 12))
	echo "Running experiment 11:($x/10)."
	./robogen-server 80$num &>/dev/null &
	./robogen-evolver $RANDOM objectiveResults/complexityCost/Experiment11/objective_output11 ../projectSimulations/objective_based_cost/evolConf11.txt --save-all --complexity-cost
	echo "Experiment 11:($x/10) finished."
done
echo "Experiment set 11 finished..."
