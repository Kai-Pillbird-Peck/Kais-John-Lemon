using UnityEngine;
using UnityEngine.UI;
using TMPro;
public class TimerScript : MonoBehaviour
{
    public float TimeLeft;
    public bool TimerOn = false;
    public TextMeshProUGUI TimerTxt;
    public GameEnding gameEnding;

    public AudioSource audioData;



    void Start()
    {
        TimerOn = true;
        audioData = GetComponent<AudioSource>();
    }

    void Update()
    {

        if (TimerOn)
        {
            if (TimeLeft > 0)
            {

                TimeLeft -= Time.deltaTime;
                updateTimer(TimeLeft);
            }
            else
            {
                Debug.Log("Time is UP!");
                TimeLeft = 0;
                TimerOn = false;

                gameEnding.CaughtPlayer();

            }
        }
    }

    void updateTimer(float currentTime)
    {
        currentTime += 1;

        float minutes = Mathf.FloorToInt(currentTime / 60);
        float seconds = Mathf.FloorToInt(currentTime % 60);

        TimerTxt.text = string.Format("{0:00}:{1:00}", minutes, seconds);


    }

}