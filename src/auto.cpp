#include "auto.h"

using namespace vex;

unsigned short int X_ERROR = 15;
// int Y_ERROR = 10;

void test(vision vis, signature sig) {
  while (true) {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    vis.takeSnapshot(sig);
    Brain.Screen.print(vis.objectCount);
    wait(1, seconds);
  }
}

void autonomous() { approach(true, Vision20__DONUT); }

void approach(bool twenty, signature sig) {
  if (twenty) {
    // if vision20 is being used

    while (true) {
      // TODO: largest object instead of objects[0]

      // vision: 316 across, 212 down

      Brain.Screen.clearScreen();

      Vision20.takeSnapshot(sig);

      if (Vision20.objects[0].exists) {

        // TODO: new calculation using scaling
        Brain.Screen.print("hello");

        unsigned short int y_center = Vision20.objects[0].centerY;
        unsigned short int x_center = Vision20.objects[0].centerX;

        double left = (0.5 * (316 * ((y_center + 70.67) / 353.3)));
        double x_range = (316 * (1 - ((y_center + 70.67) / 353.3)));
        double right = left + x_range;

        // TODO: draw center of object and the vision lines?

        if (x_center < left) {
          while (x_center < left) {
            Drivetrain.turn(left);
            Vision20.takeSnapshot(sig);
            x_center = Vision20.objects[0].centerX;
          }
        } else if (x_center > right) {
          while (x_center > right) {
            Drivetrain.turn(right);
            Vision20.takeSnapshot(sig);
            x_center = Vision20.objects[0].centerX;
          }
        } else {
          Brain.Screen.print("forward");
          Drivetrain.drive(forward);
        }

      } else {
        Drivetrain.stop();
        Brain.Screen.print("nothing detected");
      }
    }
  }
}

void approach(bool twenty, signature sig) {
  if (twenty) {
    while (true) {
      // TODO: largest object instead of objects[0]

      // vision: 316 pixels across, 212 down !!!
      Brain.Screen.clearScreen();
      // Brain.Screen.setCursor(1, 1);

      Vision20.takeSnapshot(sig);

      // vision takes picture

      if (Vision20.objects[0].exists) {

        int x_center = Vision20.objects[0].centerX;

        // if the donut is there, print the x value of center
        // Brain.Screen.print(Vision20.objects[0].centerX);

        Brain.Screen.drawCircle(Vision20.objects[0].centerX,
                                Vision20.objects[0].centerY, 5);

        if (x_center < (158 - X_ERROR)) {
          while (x_center < (158 - X_ERROR)) {
            Drivetrain.turn(left);
            Vision20.takeSnapshot(sig);
            x_center = Vision20.objects[0].centerX;
          }
        }

        if (x_center > (158 + X_ERROR)) {
          while (x_center > (158 + X_ERROR)) {
            Drivetrain.turn(right);
            Vision20.takeSnapshot(sig);
            x_center = Vision20.objects[0].centerX;
          }
        }

        if (x_center < (158 - X_ERROR) && x_center > (158 + X_ERROR)) {

          while (x_center < (158 - X_ERROR) && x_center > (158 + X_ERROR)) {

            Brain.Screen.print("forward");
            Drivetrain.drive(forward);
          }
        }

      } else {
        Drivetrain.stop();
        Brain.Screen.print("nothing detected :(");
      }
    }
  }
}