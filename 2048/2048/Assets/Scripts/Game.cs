using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;

public class Game : MonoBehaviour
{
    // creates an multi dimentional array called grid that is defined by gridHeight and gridWidth
    public static int gridWidth = 4, gridHeight = 4;

    public static Transform[,] grid = new Transform[gridWidth, gridHeight];

    // creates a link to a custom tool
    public CFDebug debug;

    // Start is called before the first frame update
    void Start()
    {
        GenerateNewTile(2);
    }


    // Update is called once per frame
    void Update()
    {
        CheckUserInput();

        //debug.Add("Current Time", Time.time.ToString() , "currenttime");
    }


    /// <summary>
    /// Checks if the user is pressing up down left or right
    /// </summary>
    void CheckUserInput()
    {
        // sets bool values if a key is currently presses on the frame this function is called
        bool down = Input.GetKeyDown(KeyCode.DownArrow),
             up = Input.GetKeyDown(KeyCode.UpArrow),
             left = Input.GetKeyDown(KeyCode.LeftArrow),
             right = Input.GetKeyDown(KeyCode.RightArrow);

        if(down || up || left || right)
        {
            if (down)
            {
                debug.Add("Player Pressed Key", "Down", "CheckUserInput");

                GetRandomLocation();
            }
            if (up)
            {
                debug.Add("Player Pressed Key", "Up", "CheckUserInput");
            }
            if (left)
            {
                debug.Add("Player Pressed Key", "Left", "CheckUserInput");
            }
            if (right)
            {
                debug.Add("Player Pressed Key", "Right", "CheckUserInput");
            }
        }
    }


    /// <summary>
    /// Creates a how ever many new tile game object in the game
    /// </summary>
    /// <param name="howMany"></param>
    void GenerateNewTile(int howMany)
    {
        // loops through how ever many tiles that are being called
        for (int i = 0; i < howMany; ++i)
        {
            // getting a random location and storing it
            Vector2 newLocation = GetRandomLocation();

            // storing the name of the prefab tile
            string tile = "tile_2";

            float chanceOfTwo = Random.Range(0f, 1f);

            if (chanceOfTwo > 0.9f)
                tile = "tile_4";

            // creating a newTile game object that is using the string tile and the new location data from above
            GameObject newTile = (GameObject)Instantiate(Resources.Load(tile, typeof(GameObject)), newLocation, Quaternion.identity);

            // makes the new tile that was just created be parented to the grid game object
            newTile.transform.parent = transform;
        }
    }


    /// <summary>
    /// Searches the grid for a random location that is free of tiles and returns a vector 2 of that free location
    /// </summary>
    /// <returns></returns>
    Vector2 GetRandomLocation()
    {
        // creating lists (which are arrays that can grow with new entries) to store avalible grid spaces
        List<int> x = new List<int>();
        List<int> y = new List<int>();

        // iterating through every grid space and if its empty, put its location in the lists
        for (int j = 0; j < gridWidth; j++)
        {
            for (int i = 0; i < gridHeight; i++)
            {
                if (grid[j, i] == null)
                {
                    x.Add(j);
                    y.Add(i);
                }
            }
        }

        // takes a random number from 0 to the amount of items in the list and sets randX/Y as the corrisponding element in the lists
        int randIndex = Random.Range(0, x.Count);

        int randX = x.ElementAt(randIndex);
        int randY = y.ElementAt(randIndex);

        debug.Add("New Random Tile Location", randX + ", " + randY, "randomlocation");

        // returns a vector2 with the random avalible location
        return new Vector2(randX, randY);
    }


    /// <summary>
    /// Restarts gameplay
    /// </summary>
    public void PlayAgain()
    {
        // sets grid array to brand new array
        grid = new Transform[gridWidth,gridHeight];
    }
}
