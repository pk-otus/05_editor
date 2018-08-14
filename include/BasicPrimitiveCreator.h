#pragma once
#include <vector>
#include <algorithm>

#include "GraphicEditor.h"
#include "ConcreteFigures.h"

namespace GraphicEditor
{
	template<typename FIGURE>
	class BasicPrimitiveCreator : public IGraphicPrimitiveCreator
	{
	public:
		IGraphicPrimitive * CreatePrimitive(EnumFigure figure_type) override
		{
			all_figures.push_back(CreateNewFigure(figure_type));
			return all_figures.back();
		}

		void DeletePrimitive(IGraphicPrimitive* p) override
		{
			auto fig = std::find_if(all_figures.begin(), all_figures.end(),
				[p](FIGURE* d) {return dynamic_cast<FIGURE*>(p) == d; });

			delete *fig;

			all_figures.erase(
				std::remove(all_figures.begin(), all_figures.end(), *fig),
				all_figures.end());		
		}

		void TransformCirclesToSquares() override
		{
			for (FIGURE* fig : all_figures)
			{
				if (dynamic_cast<const Circle*>(fig->GetFigure()))
				{
					fig->ChangeFigure(EnumFigure::Square);
				}
			}
		}
	private:
		virtual FIGURE* CreateNewFigure(EnumFigure figure_type) const = 0;

		std::vector<FIGURE*> all_figures;
	};
}
