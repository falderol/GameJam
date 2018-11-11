﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Room1BlackTerminal : MonoBehaviour
{
    public Animator anim;
    public string correctCubeColor;
    public bool undoCor;
    public bool undoWrong;

    //Audio For Doors
    public AudioSource[] PlayerAS;
    public AudioClip[] doorClip;
    public bool doorSound;
    //Audio For Button Sound
    public AudioSource button;
    public AudioClip[] buttonClip;
    //public bool buttonSound; //We may or may not use this depending on how it sounds
    //Stuff that alex did
    public Animator[] anim2;
    public string[] CoranimOn;
    public string[] CoranimOff;
    public Transform[] CoractiveOn;
    public Transform[] CoractiveOff;
    public string[] WronganimOn;
    public string[] WronganimOff;
    public Transform[] WrongactiveOn;
    public Transform[] WrongactiveOff;

	private int numCubesDetected;

	void OnTriggerEnter(Collider other) {
		if (!anim.GetBool("boxPresent")) {
			if (other.gameObject.tag == "PickUpAble") {
				if (numCubesDetected == 0) {
					anim.SetBool ("boxPresent", true);
					if (other.gameObject.name.IndexOf (correctCubeColor) != -1) {
						
						PlayerAS [0].Stop ();
						//FIXME if light noises, play here
						anim.SetBool ("CorrectAnswer", true);
						anim.SetBool ("WrongAnswer", false);
						button.PlayOneShot (buttonClip [0]);//If it sounds bad put this in if
						if (doorSound) {
							PlayerAS [0].PlayOneShot (doorClip [0]);
						}
						CorrectEffect ();

					} 
					else {
						button.PlayOneShot (buttonClip [1]);//If it sounds bad put this in if
						WrongEffect ();
						anim.SetBool ("CorrectAnswer", false);
						anim.SetBool ("WrongAnswer", true);
					}
				}
				numCubesDetected++;
			}
        }
    }

    void OnTriggerExit(Collider other) {
		if (other.gameObject.tag == "PickUpAble") {
			if (numCubesDetected == 1) {
				if (anim.GetBool ("CorrectAnswer") && undoCor) {
					UndoCorrectEffect ();
					if (doorSound) {
						PlayerAS[0].PlayOneShot (doorClip [1]);
					}
				}
				if (anim.GetBool ("WrongAnswer") && undoWrong) {
					UndoWrongEffect ();
				}
				anim.SetBool ("CorrectAnswer", false);
				anim.SetBool ("WrongAnswer", false);
				anim.SetBool ("boxPresent", false);
			}
			numCubesDetected--;
		}
    }

	void OnTriggerStay(Collider other) {
		if (other.tag == "PickUpAble") {
			if (ObjectControl2.pickedUp == false) {
				if (numCubesDetected == 1) {
					other.transform.position = transform.position;
					other.transform.rotation = new Quaternion (0, 0, 0, 0);
				}
			}
		}
	}

    void CorrectEffect()
    {
        foreach (string value in CoranimOn)
        {
            anim2[0].SetBool(value, true);
        }
        foreach (string value in CoranimOff)
        {
            anim2[0].SetBool(value, false);
        }
        foreach (Transform value in CoractiveOn)
        {
            value.gameObject.SetActive(true);
        }
        foreach (Transform value in CoractiveOff)
        {
            value.gameObject.SetActive(false);
        }
    }

    void UndoCorrectEffect()
    {
        foreach (string value in CoranimOn)
        {
            anim2[0].SetBool(value, false);
        }
        foreach (string value in CoranimOff)
        {
            anim2[0].SetBool(value, true);
        }
        foreach (Transform value in CoractiveOn)
        {
            value.gameObject.SetActive(false);
        }
        foreach (Transform value in CoractiveOff)
        {
            value.gameObject.SetActive(true);
        }
    }

    void WrongEffect()
    {
        foreach (string value in WronganimOn)
        {
            anim2[0].SetBool(value, true);
        }
        foreach (string value in WronganimOff)
        {
            anim2[0].SetBool(value, false);
        }
        foreach (Transform value in WrongactiveOn)
        {
            value.gameObject.SetActive(true);
        }
        foreach (Transform value in WrongactiveOff)
        {
            value.gameObject.SetActive(false);
        }
    }

    void UndoWrongEffect()
    {
        foreach (string value in WronganimOn)
        {
            anim2[0].SetBool(value, false);
        }
        foreach (string value in WronganimOff)
        {
            anim2[0].SetBool(value, true);
        }
        foreach (Transform value in WrongactiveOn)
        {
            value.gameObject.SetActive(false);
        }
        foreach (Transform value in WrongactiveOff)
        {
            value.gameObject.SetActive(true);
        }
    }
}
