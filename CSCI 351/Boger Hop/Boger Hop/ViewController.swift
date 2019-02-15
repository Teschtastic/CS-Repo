//
//  ViewController.swift
//  Boger Hop
//
//  Created by Sean Tesch on 9/30/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var boger1: UIImageView!
    @IBOutlet weak var boger2: UIImageView!
    @IBOutlet weak var boger3: UIImageView!
    @IBOutlet weak var boger4: UIImageView!
    @IBOutlet weak var boger5: UIImageView!
    @IBOutlet weak var speedSlider: UISlider!
    @IBOutlet weak var speedStepper: UIStepper!
    @IBOutlet weak var toggleButton: UIButton!
    @IBOutlet weak var hps: UILabel!
    
    @IBAction func setSpeed(sender: AnyObject) {
        
        boger1.animationDuration = TimeInterval(2 - speedSlider.value)
        boger2.animationDuration = boger1.animationDuration + TimeInterval((Float)(rand()%11+1)/10)
        boger3.animationDuration = boger1.animationDuration + TimeInterval((Float)(rand()%11+1)/10)
        boger4.animationDuration = boger1.animationDuration + TimeInterval((Float)(rand()%11+1)/10)
        boger5.animationDuration = boger1.animationDuration + TimeInterval((Float)(rand()%11+1)/10)
        
        boger1.startAnimating()
        boger2.startAnimating()
        boger3.startAnimating()
        boger4.startAnimating()
        boger5.startAnimating()
        
        toggleButton.setTitle("Stop!", for: UIControlState.Normal[])
        
        let hopsRateString = NSString(format: "%.2f", 1/(2-speedSlider.value))
        hps.text = hopsRateString as String
        speedStepper.value = Double(speedSlider.value)

    }
    
    @IBAction func setIncrement(sender: AnyObject) {
        speedSlider.value = Float(speedStepper.value)
        setSpeed(sender: sender)
    }
    
    @IBAction func toggleAnimation(sender: AnyObject) {
        
        if (boger1.isAnimating) {
            
            boger1.stopAnimating()
            boger2.stopAnimating()
            boger3.stopAnimating()
            boger4.stopAnimating()
            boger5.stopAnimating()
            
            toggleButton.setTitle("Hop!", for: UIControlState.Normal[])
        }
        else {
            
            boger1.startAnimating()
            boger2.startAnimating()
            boger3.startAnimating()
            boger4.startAnimating()
            boger5.startAnimating()
            
            toggleButton.setTitle("Stop!", for: UIControlState.Normal[])
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        var imageListArray: [UIImage] = []

        for countValue in 1...20 {
            let strImageName : String = "frame-\(countValue).png"
            let image = UIImage(named: strImageName)
            imageListArray.append(image!)
        }
        
        boger1.animationImages = imageListArray
        boger1.animationDuration = 1.0
        boger2.animationImages = imageListArray
        boger2.animationDuration = 1.0
        boger3.animationImages = imageListArray
        boger3.animationDuration = 1.0
        boger4.animationImages = imageListArray
        boger4.animationDuration = 1.0
        boger5.animationImages = imageListArray
        boger5.animationDuration = 1.0
        
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

