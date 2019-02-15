//
//  ViewController.swift
//  Basketball Timer
//
//  Created by Sean Tesch on 10/20/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import AVFoundation

class ViewController: UIViewController {
    var player = AVAudioPlayer()
    var timerRunning = false
    var timerCount = 60
    var timer = NSTimer()
    
    @IBOutlet weak var startStop: UIButton!
    @IBOutlet weak var timerLabel: UILabel!
    
    @IBAction func startButton(sender: AnyObject) {
        if (!timerRunning) {
            timer = NSTimer.scheduledTimerWithTimeInterval(1, target: self, selector: Selector("counting"), userInfo: nil, repeats: true)
            timerRunning = true
        }
        if (timerRunning) {
        }
    }
    
    @IBAction func fullButton(sender: AnyObject) {
        startStop.enabled = true
        timerCount = 60
        timerLabel.text = "\(timerCount)"
        self.view.backgroundColor = UIColor.whiteColor()
        startStop.setTitle("START", forState: UIControlState.Normal)
    }
    
    @IBAction func halfButton(sender: AnyObject) {
        startStop.enabled = true
        timerCount = 30
        timerLabel.text = "\(timerCount)"
        self.view.backgroundColor = UIColor.whiteColor()
        startStop.setTitle("START", forState: UIControlState.Normal)
    }
    
    func counting() {
        timerCount--
        timerLabel.text = "\(timerCount)"
        
        if (timerCount == 15) {
            self.view.backgroundColor = UIColor.orangeColor()
            player.play()
        }
        
        if (timerCount == 0) {
            self.view.backgroundColor = UIColor.redColor()
            player.play()
        }
        
        if (timerCount == 0) {
            timer.invalidate()
            startStop.setTitle("STOP", forState: UIControlState.Normal)
            timerRunning = false
            startStop.enabled = false
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let alertSound = NSURL(fileURLWithPath: NSBundle.mainBundle().pathForResource("Buzzer", ofType: "mp3")!)
        var error:NSError?
        do {
            player = try AVAudioPlayer(contentsOfURL: alertSound)
        } catch let error1 as NSError {
            error = error1
            print("Error: \(error)")
        }
        player.prepareToPlay()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

