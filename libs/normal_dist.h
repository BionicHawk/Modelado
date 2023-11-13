#include <cmath>
#include <vector>
#include <math.h>

struct Position {
  double x;
  double y;
};

class Quadrant {
public:
  std::vector<double> numbers;
  double etiquette;

  Quadrant(double etiquette, std::vector<double> numbers) {
    this->numbers = numbers;
    this->etiquette = etiquette;
  }
};

class Row {
public:
  double min;
  double max;
  std::vector<Quadrant> rowContent;

  Row(double min, double max) {
    this->min = min;
    this->max = max;
    this->rowContent = {};
  }

  void setQuadrant(std::vector<double> numbers) {
    double etiquette = rowContent.size() * std::pow(10, -2);
    rowContent.push_back(Quadrant(etiquette, numbers));
  }

};

class Table {
public:
  Table() {
    rows = {};
    setRows();
  }

  double getValue(double x, double y) {
    double value = -1.0;
    for(auto row : rows) {
      if(y >= row.min && y <= row.max) {
	for(auto quadrant : row.rowContent) {
	  if (quadrant.etiquette == x) {
	    for(int i = 0; i < quadrant.numbers.size(); i++) {
	      double calculatedY = (i * std::pow(10, -1)) + row.min;
	      if((calculatedY) == y) return quadrant.numbers[i]; 
	    }
	  }
	}
      }
    }

    return value;
  }

  Position findValuePosition(double value) {
    Position position;
    position.x = -1.0;
    position.y = -1.0;

    for(auto row : rows) {
      for(auto quadrant : row.rowContent) {
	for(int i = 0; i < quadrant.numbers.size(); i++) {
	  if (quadrant.numbers[i] == value) {
	    double y = i * std::pow(10, -1);
	    position.x = quadrant.etiquette;
	    position.y = row.min + y;
	    return position; 
	  }
	}
      }
    }

    return position;
  }

private:
  std::vector<Row> rows;
  
  void setRows() {
    row1();
    row2();
    row3();
    row4();
    row5();
    row6();
  }

  void row1() {
   Row row(0.0, 0.4);
   row.setQuadrant({0.0000,0.0398,0.0793,0.1179,0.1554});
   row.setQuadrant({0.0040,0.0438,0.0832,0.1217,0.1591});
   row.setQuadrant({0.0080,0.0478,0.0871,0.1255,0.1628});
   row.setQuadrant({0.0120,0.0517,0.0910,0.1293,0.1664});
   row.setQuadrant({0.0160,0.0557,0.0948,0.1331,0.1700});
   row.setQuadrant({0.0199,0.0596,0.0987,0.1368,0.1736});
   row.setQuadrant({0.0239,0.0636,0.1026,0.1406,0.1772});
   row.setQuadrant({0.0279,0.0675,0.1064,0.1443,0.1808});
   row.setQuadrant({0.0319,0.0714,0.1103,0.1480,0.1844});
   row.setQuadrant({0.0359,0.0753,0.1141,0.1517,0.1879});
   rows.push_back(row);
  }
  
  void row2() {
   Row row(0.5, 0.9);
   row.setQuadrant({0.1915,0.2257,0.2580,0.2881,0.3159});
   row.setQuadrant({0.1950,0.2291,0.2611,0.2910,0.3186});
   row.setQuadrant({0.1985,0.2324,0.2642,0.2939,0.3212});
   row.setQuadrant({0.2019,0.2357,0.2673,0.2967,0.3238});
   row.setQuadrant({0.2054,0.2389,0.2703,0.2995,0.3264});
   row.setQuadrant({0.2088,0.2422,0.2734,0.3023,0.3289});
   row.setQuadrant({0.2123,0.2454,0.2764,0.3051,0.3315});
   row.setQuadrant({0.2157,0.2486,0.2794,0.3078,0.3340});
   row.setQuadrant({0.2190,0.2517,0.2833,0.3106,0.3365});
   row.setQuadrant({0.2224,0.2549,0.2852,0.3133,0.3389});
   rows.push_back(row);
  }

  void row3() {
   Row row(1.0, 1.4);		
   row.setQuadrant({0.3413,0.3643,0.3849,0.4032,0.4192});
   row.setQuadrant({0.3438,0.3665,0.3869,0.4049,0.4207});
   row.setQuadrant({0.3461,0.3686,0.3888,0.4066,0.4222});
   row.setQuadrant({0.3485,0.3708,0.3907,0.4082,0.4236});
   row.setQuadrant({0.3508,0.3729,0.3925,0.4099,0.4251});
   row.setQuadrant({0.3531,0.3749,0.3944,0.4115,0.4265});
   row.setQuadrant({0.3554,0.3770,0.3962,0.4131,0.4279});
   row.setQuadrant({0.3577,0.3790,0.3980,0.4147,0.4292});
   row.setQuadrant({0.3599,0.3810,0.3997,0.4162,0.4306});
   row.setQuadrant({0.3621,0.3830,0.4015,0.4177,0.4319});
   rows.push_back(row);
  }

  void row4() {
   Row row(1.5, 1.9);		
   row.setQuadrant({0.4332,0.4452,0.4554,0.4641,0.4713});
   row.setQuadrant({0.4345,0.4463,0.4564,0.4649,0.4719});
   row.setQuadrant({0.4357,0.4474,0.4573,0.4656,0.4726});
   row.setQuadrant({0.4370,0.4484,0.4582,0.4664,0.4732});
   row.setQuadrant({0.4382,0.4495,0.4591,0.4671,0.4738});
   row.setQuadrant({0.4394,0.4505,0.4599,0.4678,0.4744});
   row.setQuadrant({0.4406,0.4515,0.4608,0.4686,0.4750});
   row.setQuadrant({0.4418,0.4525,0.4616,0.4693,0.4756});
   row.setQuadrant({0.4429,0.4535,0.4625,0.4699,0.4761});
   row.setQuadrant({0.4441,0.4545,0.4633,0.4706,0.4767});
   rows.push_back(row);
  }

  void row5() {
   Row row(2.0, 2.4);		
   row.setQuadrant({0.4772,0.4821,0.4861,0.4893,0.4918});
   row.setQuadrant({0.4778,0.4826,0.4864,0.4896,0.4920});
   row.setQuadrant({0.4783,0.4830,0.4868,0.4898,0.4922});
   row.setQuadrant({0.4788,0.4834,0.4871,0.4901,0.4925});
   row.setQuadrant({0.4793,0.4838,0.4875,0.4904,0.4927});
   row.setQuadrant({0.4798,0.4842,0.4878,0.4906,0.4929});
   row.setQuadrant({0.4803,0.4846,0.4881,0.4909,0.4931});
   row.setQuadrant({0.4808,0.4950,0.4884,0.4911,0.4932});
   row.setQuadrant({0.4812,0.4854,0.4887,0.4913,0.4934});
   row.setQuadrant({0.4817,0.4857,0.4890,0.4916,0.4936});
   rows.push_back(row);
  }

  void row6() {
   Row row(2.5, 2.9);		
   row.setQuadrant({0.4938,0.4953,0.4965,0.4974,0.4981});
   row.setQuadrant({0.4940,0.4955,0.4966,0.4975,0.4982});
   row.setQuadrant({0.4941,0.4956,0.4967,0.4976,0.4982});
   row.setQuadrant({0.4943,0.4957,0.4968,0.4977,0.4983});
   row.setQuadrant({0.4945,0.4959,0.4969,0.4977,0.4984});
   row.setQuadrant({0.4946,0.4960,0.4970,0.4978,0.4984});
   row.setQuadrant({0.4948,0.4961,0.4971,0.4979,0.4985});
   row.setQuadrant({0.4949,0.4962,0.4972,0.4979,0.4985});
   row.setQuadrant({0.4951,0.4963,0.4973,0.4980,0.4986});
   row.setQuadrant({0.4952,0.4964,0.4974,0.4981,0.4986});
   rows.push_back(row);
  }

  void row7() {
    Row row(3.0, 3.0);
    row.setQuadrant({0.4987});
    row.setQuadrant({0.4987});
    row.setQuadrant({0.4987});
    row.setQuadrant({0.4988});
    row.setQuadrant({0.4988});
    row.setQuadrant({0.4989});
    row.setQuadrant({0.4989});
    row.setQuadrant({0.4989});
    row.setQuadrant({0.4990});
    row.setQuadrant({0.4990});
    rows.push_back(row);
  }
};
