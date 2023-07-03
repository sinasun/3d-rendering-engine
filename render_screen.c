#include "render_screen.h"

VkInstance initializeVulkan(SDL_Window *screen);
VkSurfaceKHR createSurface(SDL_Window *window, VkInstance vkInstance);
void getPhysicalDevice(VkInstance * vulkanInstance);

int createScreen() {
  SDL_Window *screen = NULL;
  // SDL_Surface *surfaceScreen = NULL;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Unable to initialize SDL!! error: %s", SDL_GetError());
    return -1;
  }

  screen = SDL_CreateWindow(
      "3D Rendering Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      840, 680, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN);

  if (!screen) {
    printf("Unable to create SDL window error: %s", SDL_GetError());
    return -1;
  }

  // SDL_Vulkan_CreateSurface(screen, );
  // free resources
  handleInputs(screen);

  // SDL_FreeSurface(surfaceScreen);
  SDL_DestroyWindow(screen);
  SDL_Quit();

  return 0;
}

int handleInputs(SDL_Window *screen) {
  bool run = true;
  // const unsigned delay = 20;
  //  create an event lister
  SDL_Event event;
  SDL_Renderer *renderer = NULL;
  // get the vulkan instance
  VkInstance vkInstance = initializeVulkan(screen);

  if (vkInstance == VK_NULL_HANDLE) {
    return -1;
  }
  getPhysicalDevice(&vkInstance);
  // // get the surface
   VkSurfaceKHR surface = createSurface(screen, vkInstance);

  if (surface == VK_NULL_HANDLE) {
    return -1;
  }

  // main loop
  while (run) {
    while (SDL_PollEvent(&event) != 0) {
      switch (event.type) {
        case SDL_QUIT:
          printf("SDL quit\n");
          run = false;
          vkDestroyInstance(vkInstance, NULL);
          vkDestroySurfaceKHR(vkInstance, surface, NULL);
          return -1;
          break;

        case SDL_WINDOWEVENT:
          // handel window resize
          break;
      }
    }

    drawPoints(renderer, screen, 200, 100);
  }

  return 0;
}

void drawPoints(SDL_Renderer *renderer, SDL_Window *screen, int pointX,
                int pointY) {
  // define a rectangle
  SDL_Rect rectangle;

  rectangle.x = pointX;
  rectangle.y = pointY;
  rectangle.h = 60;
  rectangle.w = 60;

  renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

  // clear the renderer
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 225, 225, 225, SDL_ALPHA_OPAQUE);

  // SDL_RenderDrawLine(renderer, 5, 4, 100, 120);

  SDL_RenderDrawRect(renderer, &rectangle);

  // display the drawing
  SDL_RenderPresent(renderer);
}

VkInstance initializeVulkan(SDL_Window *screen) {
  // get the required vulkan extensions
  unsigned extensionCount = 0;

  if (!SDL_Vulkan_GetInstanceExtensions(screen, &extensionCount, NULL)) {
    printf("unable to get the required extension for vulkan instance: %s\n",
           SDL_GetError());
    return VK_NULL_HANDLE;
  }

  const char **extensionNames =
      malloc(sizeof(char **) * extensionCount);  // get ll the extensions
  if (!SDL_Vulkan_GetInstanceExtensions(screen, &extensionCount,
                                        extensionNames)) {
    printf("unable to get the required extension for vulkan instance: %s\n",
           SDL_GetError());
    free(extensionNames);
    return VK_NULL_HANDLE;
  }
  VkInstanceCreateInfo pCreateInfo = {
      .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
      .pApplicationInfo = NULL,
      .enabledExtensionCount = extensionCount,
      .ppEnabledExtensionNames = extensionNames,
      .enabledLayerCount = 0,
  };
 

  VkInstance vulkanInstance;

  // create vulkan instance
  VkResult result = vkCreateInstance(&pCreateInfo, NULL, &vulkanInstance);
  free(extensionNames);

  if (result != VK_SUCCESS) {
    printf("Error creating vulkan instance. Error code: %d\n", result);
    return VK_NULL_HANDLE;
  }

  

  return vulkanInstance;
}

// create the surface for rendering
VkSurfaceKHR createSurface(SDL_Window *window, VkInstance vkInstance) {
  VkSurfaceKHR surface;

  if (!SDL_Vulkan_CreateSurface(window, vkInstance, &surface)) {
    printf("error creating surface instance\n");
    return VK_NULL_HANDLE;
  }

  return surface;
}

//
void getPhysicalDevice(VkInstance * vulkanInstance){

  unsigned gpuCount = 0;
  VkPhysicalDevice *physicalDevices  = NULL;
  // get all the gpu's available
  VkResult result = vkEnumeratePhysicalDevices(*vulkanInstance, &gpuCount, NULL);

  if (result != VK_SUCCESS || gpuCount == 0) {
    printf("No phyiscal devices/GPUs found\n ");
    vkDestroyInstance(*vulkanInstance, NULL);
    return ;
  }

  physicalDevices = malloc(sizeof(VkPhysicalDevice) * gpuCount);
  // create an array of gpus
  result =
      vkEnumeratePhysicalDevices(*vulkanInstance, &gpuCount, physicalDevices);

  if (result != VK_SUCCESS) {
    printf("Unable to enumerate phyiscal devices\n");
    free(physicalDevices);
    vkDestroyInstance(*vulkanInstance, NULL);
    return;
  }
  free(physicalDevices);
}