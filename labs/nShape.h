#pragma once

#include <vector>
#include <memory>

struct Point
{
	int x;
	int y;



	Point(int nx, int ny)
	{
		x = nx;
		y = ny;
	}

	Point(const Point* p)
	{
		x = p->x;
		y = p->y;
	}

};

struct NShapePoint
{
	

	Point* p;

	NShapePoint* lf;
	NShapePoint* rt;

	NShapePoint(Point* np)
	{
		p = np;
	}

};

class NShape
{
public:

	std::vector<NShapePoint*> shape;


	NShape(std::vector<NShapePoint*> shp)
	{
		shape = shp;
	}


	NShape(std::vector<Point>& vec)
	{
		if (vec.size() <= 1)
		{
			//err
		}
		else
		{
			std::vector<std::shared_ptr<Point>> pvec;
			for (int i = 0; i < vec.size(); i++)
			{
			
				pvec.push_back(
					std::make_shared<Point>(vec[i])
				);
			}

			for (int i = 0; i < vec.size(); i++)
			{
				shape.push_back
				(
					std::make_shared<NShapePoint>(pvec[i].get()).get()
				);
			}

			unsigned lf_id = shape.size() - 1;
			unsigned rt_id = 1;

			for (int i = 0; i < shape.size(); i++)
			{
				

				shape[i]->lf = shape[lf_id];
				shape[i]->rt = shape[rt_id];

				lf_id++;
				rt_id++;


				if (rt_id == shape.size() - 1)
				{
					rt_id = 0;
				}

				if (lf_id == shape.size())
				{
					lf_id = 0;
				}
			}
		}
	}

	NShapePoint* get_at(unsigned idx)
	{
		return shape[idx];
	}

	unsigned size()
	{
		return shape.size();
	}

};