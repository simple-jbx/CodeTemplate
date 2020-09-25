#include <bits/stdc++.h>

using namespace std;


/*
矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。

如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。

给出两个矩形，判断它们是否重叠并返回结果。
*/


/*
逆向思维：直接判断是否重叠不好判断，转而判断是否不重叠
*/
class Solution11 {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		if (
			rec1[2] <= rec2[0] //left
			|| rec1[0] >= rec2[2] //right
			|| rec1[1] >= rec2[3] //up
			|| rec1[3] <= rec2[1] //down
			)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};




/*
线段覆盖，若重叠则必然存在若干重叠线段，即两个矩形在x 和 y 轴的投影都有重叠
*/

class Solution12 {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		if (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0])
			&& min(rec1[3], rec2[3]) > max(rec1[1], rec2[1])
			)
		{
			return true;
		}
		return false;
	}
};
