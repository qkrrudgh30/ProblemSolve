
#include <string>
#include <cmath>

std::string encryption(std::string s) {

	size_t StringLength = s.length();
	size_t RowCount = std::floor(std::sqrt(StringLength));
	size_t ColumnCount = std::ceil(std::sqrtf(StringLength));
	if (RowCount * ColumnCount < StringLength)
	{
		RowCount = ColumnCount;
	}

	std::string Result;
	for (size_t j = 0; j < ColumnCount; ++j)
	{
		for (size_t i = 0; i < RowCount; ++i)
		{
			size_t D1Index = i * ColumnCount + j;
			if (D1Index < StringLength)
			{
				Result += s[D1Index];
			}
		}

		if (j < ColumnCount - 1)
		{
			Result += " ";
		}
	}

	return Result;
}
