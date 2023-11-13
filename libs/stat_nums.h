#include <cmath>
#include <vector>

class StatSizeRow{
public:
  int n;
  double x;
  double y;
  double z;

  StatSizeRow(int n, double x, double y, double z) {
    this->n = n;
    this->x = x;
    this->y = y;
    this->z = z;
  }

};

class StatSize {
public:
  const int alpha_x = 10;
  const int alpha_y = 5;
  const int alpha_z = 1;

  StatSize() {
    set_default_table();
  }

  double gen_x(int n) {
    return 1.22 / std::sqrt(n);
  }

  double gen_y(int n) {
    return 1.36 / std::sqrt(n);
  }

  double gen_z(int n) {
    return 1.63 / std::sqrt(n);
  }

  double get_stat(unsigned int n, unsigned int percent) {
    bool founded = false;

    if (n > 100) {
      switch (percent) {
	case 1:
	  return gen_z(n);
	  break;
	case 5:
	  return gen_y(n);
	  break;
	case 10:
	  return gen_x(n);
	  break;
      }
    }

    for (int i = 0; i < rows.size(); i++) {
      if (rows[i].n == n) {
	founded = true;
	switch(percent) {
	  case 1:
	    return rows[i].z;
	    break;
	  case 5:
	    return rows[i].y;
	    break;
	  case 10:
	    return rows[i].x;
	    break;
	}
      }
    }

    if (!founded) {
      switch(percent) {
	case 1:
	  return gen_z(n);
	  break;
	case 5:
	  return gen_y(n);
	  break;
	case 10:
	  return gen_x(n);
	  break;
      }
    }

    return -1.0;
  }

private:
  std::vector<StatSizeRow> rows;

  void set_default_table() {
    rows = {
      StatSizeRow(1, 	0.950, 		0.975, 0.995	),
      StatSizeRow(2, 	0.776, 		0.842, 0.929	),
      StatSizeRow(3, 	0.642, 		0.708, 0.829	),
      StatSizeRow(4, 	0.564, 		0.624, 0.734	),
      StatSizeRow(5, 	0.510, 		0.563, 0.669	),
      StatSizeRow(6, 	0.470, 		0.521, 0.618	),
      StatSizeRow(7, 	0.438,	 	0.486, 0.577	),
      StatSizeRow(8, 	0.411,	 	0.452, 0.543	),
      StatSizeRow(9, 	0.388,	 	0.432, 0.514	),
      StatSizeRow(10, 	0.368,	 	0.409, 0.486	),
      StatSizeRow(11, 	0.352,	 	0.391, 0.468	),
      StatSizeRow(12, 	0.338,	 	0.375, 0.450	),
      StatSizeRow(13, 	0.352,	 	0.361, 0.433	),
      StatSizeRow(14, 	0.314,	 	0.349, 0.418	),
      StatSizeRow(15, 	0.304,	 	0.338, 0.404	),
      StatSizeRow(16, 	0.295,	 	0.328, 0.392	),
      StatSizeRow(17, 	0.286,	 	0.318, 0.381	),
      StatSizeRow(18, 	0.278,	 	0.309, 0.371	),
      StatSizeRow(19, 	0.272,	 	0.301, 0.363	),
      StatSizeRow(20, 	0.264,	 	0.294, 0.352	),
      StatSizeRow(25, 	0.240,	 	0.264, 0.317	),
      StatSizeRow(30, 	0.220, 		0.242, 0.290	),
      StatSizeRow(35, 	gen_x(35),	0.230, 0.270	),
      StatSizeRow(40, 	gen_x(40), 	0.210, 0.252	),
      StatSizeRow(50, 	gen_x(50), 	0.188, 0.226	),
      StatSizeRow(60, 	gen_x(60), 	0.172, 0.207	),
      StatSizeRow(70, 	gen_x(70), 	0.160, 0.192	),
      StatSizeRow(80, 	gen_x(80), 	0.150, 0.180	),
      StatSizeRow(90, 	gen_x(90), 	0.141, gen_z(90)),
      StatSizeRow(100,	gen_x(100), 	0.134, gen_z(100)),
    };
    
    

  }

};
