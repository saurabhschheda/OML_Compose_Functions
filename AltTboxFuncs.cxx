#include <vector>

#include "AltTboxFuncs.h"
#include "OMLInterfacePublic.h"
#include "graph.h"

bool Dijkstra(OMLInterface*, const OMLCurrencyList* inputs, OMLCurrencyList* outputs);

int InitToolbox(OMLInterface* eval)
{
	eval->RegisterFunction("dijkstra", Dijkstra);

	return 0;
}

bool Dijkstra(OMLInterface* eval, const OMLCurrencyList* inputs, OMLCurrencyList* outputs)
{
	const OMLCurrency* graphData = inputs->Get(0);
	const OMLCurrency* source = inputs->Get(1);

	if (!source)
	{
		eval->ThrowError("Expected two inputs, one given");
		return true;
	}

	if (graphData->IsMatrix())
	{
		
		const OMLMatrix* mtx = graphData->GetMatrix();
		const double* data = mtx->GetRealData();		
		const int size = mtx->GetRows();
		
		double *distances = dijkstra(getVector(size, data), int(source->GetScalar()));

		OMLMatrix* distance = outputs->CreateMatrix(1, size, distances);
		outputs->AddMatrix(distance);
		
	} 
	else 
	{
		eval->ThrowError("Unexpected input");
	}

	return true;
}
