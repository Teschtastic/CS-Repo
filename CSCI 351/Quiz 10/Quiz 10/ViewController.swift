//
//  ViewController.swift
//  Quiz 10
//
//  Created by Sean Tesch on 11/13/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import SceneKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let scnView = self.view as! SCNView
        scnView.scene = PrimitivesScene()
        scnView.backgroundColor = UIColor.blackColor()
        scnView.autoenablesDefaultLighting = true
        scnView.allowsCameraControl = true
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

