//
//  PrimitivesScene.swift
//  Quiz 10
//
//  Created by Sean Tesch on 11/13/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import SceneKit

class PrimitivesScene: SCNScene {
    override init() {
        super.init()
    
    
        let plane = SCNPlane(width: 5.0, height: 5.0)
        plane.firstMaterial?.diffuse.contents = UIColor.greenColor()
        plane.firstMaterial?.doubleSided = true
        let planeNode = SCNNode(geometry: plane)
        self.rootNode.addChildNode(planeNode)

        let sphere = SCNSphere(radius: 0.6)
        sphere.firstMaterial?.diffuse.contents = UIColor.redColor()
        let sphereNode = SCNNode(geometry: sphere)
        sphereNode.position = SCNVector3(x: 2.6, y: 0.0, z: 0.5)
        self.rootNode.addChildNode(sphereNode)
    
        let sphere2 = SCNSphere(radius: 0.5)
        sphere2.firstMaterial?.diffuse.contents = UIColor.yellowColor()
        let sphereNode2 = SCNNode(geometry: sphere2)
        sphereNode2.position = SCNVector3(x: -2.6, y: 0.0, z: 0.5)
        self.rootNode.addChildNode(sphereNode2)
    
        let box = SCNBox(width: 2.0, height: 1.0, length: 1.5, chamferRadius: 0.0)
        box.firstMaterial?.diffuse.contents = UIColor.blueColor()
        let boxNode = SCNNode(geometry: box)
        boxNode.position = SCNVector3(x: 0.0, y: 0.0, z: 0.0)
        self.rootNode.addChildNode(boxNode)

        let pyramid = SCNPyramid(width: 2.0, height: 1.0, length: 1.0)
        pyramid.firstMaterial?.diffuse.contents = UIColor.orangeColor()
        let pyramidNode = SCNNode(geometry: pyramid)
        pyramidNode.position = SCNVector3(x: 0.0, y: 0.0, z: 0.75)
        pyramidNode.rotation = SCNVector4(x: 1, y: 0, z: 0, w: Float(M_PI / 2))
        self.rootNode.addChildNode(pyramidNode)
    
    }
    
    required init(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
