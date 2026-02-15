#include "robot_simulator.h"
#include <string.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y){
   robot_status_t robot;
   robot.direction = direction;
   robot.position.x = x;
   robot.position.y = y;
   return robot;
}

void robot_move(robot_status_t *robot, const char *commands){
   for (int ci=0;ci<(int)strlen(commands);ci++) {
      switch (commands[ci]) {
        case 'A': switch(robot->direction) {
            case DIRECTION_NORTH: robot->position.y++; break;
            case DIRECTION_EAST: robot->position.x++; break;
            case DIRECTION_SOUTH: robot->position.y--; break;
            case DIRECTION_WEST: robot->position.x--; break;
            default:;
         }; break;
        case 'L': switch(robot->direction) {
            case DIRECTION_NORTH: robot->direction = DIRECTION_WEST; break;
            case DIRECTION_EAST: robot->direction = DIRECTION_NORTH; break;
            case DIRECTION_SOUTH:robot->direction = DIRECTION_EAST; break;
            case DIRECTION_WEST:robot->direction = DIRECTION_SOUTH; break;
            default:;
        }; break;
        case 'R': switch(robot->direction) {
            case DIRECTION_NORTH: robot->direction = DIRECTION_EAST; break;
            case DIRECTION_EAST: robot->direction = DIRECTION_SOUTH; break;
            case DIRECTION_SOUTH:robot->direction = DIRECTION_WEST; break;
            case DIRECTION_WEST:robot->direction = DIRECTION_NORTH; break;
            default:;
        }; break;
      }  
   }

}