//
//  ViewController.swift
//  Motion
//
//  Created by Sean Tesch on 11/11/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import CoreMotion

class ViewController: UIViewController {
    @IBOutlet weak var xacc: UILabel!
    @IBOutlet weak var yacc: UILabel!
    @IBOutlet weak var zacc: UILabel!
    @IBOutlet weak var maxxacc: UILabel!
    @IBOutlet weak var maxyacc: UILabel!
    @IBOutlet weak var maxzacc: UILabel!
    @IBOutlet weak var xrot: UILabel!
    @IBOutlet weak var yrot: UILabel!
    @IBOutlet weak var zrot: UILabel!
    @IBOutlet weak var maxxrot: UILabel!
    @IBOutlet weak var maxyrot: UILabel!
    @IBOutlet weak var maxzrot: UILabel!
    
    var currentMaxAccelX: Double = 0.0
    var currentMaxAccelY: Double = 0.0
    var currentMaxAccelZ: Double = 0.0
    var currentMaxRotX: Double = 0.0
    var currentMaxRotY: Double = 0.0
    var currentMaxRotZ: Double = 0.0
    
    var motionManager = CMMotionManager()

    @IBAction func resetButton(sender: AnyObject) {
        currentMaxAccelX = 0
        currentMaxAccelY = 0
        currentMaxAccelZ = 0
        currentMaxRotX = 0
        currentMaxRotY = 0
        currentMaxRotZ = 0
    }
    
    override func viewDidLoad() {
        resetButton(self)
        
        // Set Motion Manager Properties
        motionManager.gyroUpdateInterval = 0.2
        motionManager.accelerometerUpdateInterval = 0.2
        
        // Start Recording Data
        motionManager.startAccelerometerUpdatesToQueue(NSOperationQueue.currentQueue()!, withHandler: {
            (accelerometerData,error) in
            self.outputAccelerationData(accelerometerData!.acceleration)
            if(error != nil) {
                print("\(error)")
            }
        })
        
        motionManager.startGyroUpdatesToQueue(NSOperationQueue.currentQueue()!, withHandler:
            { (gyroData, error) in
                self.outputRotationData(gyroData!.rotationRate)
                if(error != nil){
                    print("\(error)")
                }
        })
        
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    func outputAccelerationData (acceleration: CMAcceleration) {
        xacc.text = "\(acceleration.x)"
        if fabs(acceleration.x) > fabs(currentMaxAccelX) {
            currentMaxAccelX = acceleration.x
        }
        yacc.text = "\(acceleration.y)"
        if fabs(acceleration.y) > fabs(currentMaxAccelY) {
            currentMaxAccelY = acceleration.y
        }
        zacc.text = "\(acceleration.z)"
        if fabs(acceleration.z) > fabs(currentMaxAccelZ) {
            currentMaxAccelZ = acceleration.z
        }
        maxxacc.text = "\(currentMaxAccelX)"
        maxyacc.text = "\(currentMaxAccelY)"
        maxzacc.text = "\(currentMaxAccelZ)"
    }
    
    func outputRotationData (rotation: CMRotationRate) {
        xrot.text = "\(rotation.x)"
        if fabs(rotation.x) > fabs(currentMaxRotX) {
            currentMaxRotX = rotation.x
        }
        yrot.text = "\(rotation.y)"
        if fabs(rotation.y) > fabs(currentMaxRotY) {
            currentMaxRotY = rotation.y
        }
        zrot.text = "\(rotation.z)"
        if fabs(rotation.z) > fabs(currentMaxRotZ) {
            currentMaxRotZ = rotation.z
        }
        maxxrot.text = "\(currentMaxRotX)"
        maxyrot.text = "\(currentMaxRotY)"
        maxzrot.text = "\(currentMaxRotZ)"
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

