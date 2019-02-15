//
//  ViewController.swift
//  Timers
//
//  Created by Sean Tesch on 10/14/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import AVFoundation

class ViewController: UIViewController {
    var player = AVAudioPlayer()
    var timerRunning = false
    var timerCount = 0
    var timer = NSTimer()

    @IBOutlet weak var timerLabel: UILabel!
    
    @IBAction func startButton(sender: AnyObject) {
        if (!timerRunning) {
            timer = NSTimer.scheduledTimerWithTimeInterval(1, target: self, selector: Selector("counting"), userInfo: nil, repeats: true)
            timerRunning = true
        }
    }
    
    @IBAction func stopButton(sender: AnyObject) {
        if (timerRunning) {
            timer.invalidate()
            timerRunning = false
        }
    }
    
    @IBAction func resetButton(sender: AnyObject) {
        timerCount = 0
        timerLabel.text = "0"
    }
    
    func counting() {
        timerCount++
        timerLabel.text = "\(timerCount)"
        
        if (timerCount == 4) {
            self.view.backgroundColor = UIColor.greenColor()
            player.play()
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let alertSound = NSURL(fileURLWithPath: NSBundle.mainBundle().pathForResource("Inception", ofType: "mp3")!)
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

