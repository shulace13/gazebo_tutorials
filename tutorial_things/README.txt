Hello
 Just shoots out "Hello, World!\n" when you execute the following
 $ gzserver hello.world --verbose
 This is the first example you will see when learning about the plugins.

Factory
 Assuming you're in this directory, execute the following
 $ gazebo factory.world
 Then, you should see three shapes apear. sphere box and cylinder.
 These shapes are imported in three different ways. see the factory.cc for detail

Model Push
 execute the following. the -u flag means to start the program but pause the simulation
 $ gzserver -u model_push.world
 Then in another terminal, execute the following
 $ gzclient
 You should see a box and when you press play on the bottom of the window
 That should move.

System GUI

World Edit
 This world has a reverse gravity. Anything you put in this world will go up.
 $ gazebo world_edit.world

