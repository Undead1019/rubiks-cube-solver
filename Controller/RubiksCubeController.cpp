#include "RubiksCubeController.h"

void exitHandler(int s)
{
  exit(0); 
}

namespace busybin
{
  /**
   * Main controller.  Sets up the World, Views, and commands.
   */
  void RubiksCubeController::run()
  {
#ifndef _WIN32
    // Handle CTRL-C by exiting with a 0 status code.  This is needed if
    // running the GNU profiler, gprof, which writes at exit.
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = exitHandler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags   = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);
#endif

    try
    {
      // Pass width and height for windowed-mode.
      WorldWindow              worldWnd("Rubik's Cube", 1024, 768);
      RubiksCubeWorld          world(unique_ptr<Program>(new RubiksCubeProgram()));
      ViewManager              viewMan(&world,    &worldWnd);
      Renderer                 renderer(&world,   &worldWnd);
      CubeMover                cubeMover(&world,  &worldWnd);
      ThreadPool               threadPool(1);
      ThistlethwaiteCubeSolver tCubeSolver(&world, &worldWnd, &cubeMover, &threadPool);
      KorfCubeSolver           kCubeSolver(&world, &worldWnd, &cubeMover, &threadPool);
      CubeDumper               cubeDumper(&world, &worldWnd);
      CubeScrambler            cubeScrambler(&world, &worldWnd, &cubeMover);

      tCubeSolver.initialize();
      kCubeSolver.initialize();
cout << "Starting main rendering loop..." << endl;

      // All wired up, run the main loop.
      worldWnd.run();
    }
    catch (const exception& ex)
    {
      cout << "Exception encountered.\n" << ex.what() << endl;
      exit(1); 
    }
  }
}
