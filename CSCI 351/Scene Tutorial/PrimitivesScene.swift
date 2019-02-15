//
//  PrimitivesScene.swift
//  Scene Tutorial
//
//  Created by Sean Tesch on 11/12/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import SceneKit

class PrimitivesScene: SCNScene {
    override init() {
        super.init()
        
        /* let sphereGeometry = SCNSphere(radius: 1.0)
        sphereGeometry.firstMaterial?.diffuse.contents = UIColor.orangeColor()
        let sphereNode = SCNNode(geometry: sphereGeometry)
        self.rootNode.addChildNode(sphereNode)
        
        let secondSphereGeometry = SCNSphere(radius: 0.5)
        secondSphereGeometry.firstMaterial?.diffuse.contents = UIColor.purpleColor()
        let secondSphereNode = SCNNode(geometry: secondSphereGeometry)
        secondSphereNode.position = SCNVector3(x: 3.0, y: 0.0, z: 0.0)
        self.rootNode.addChildNode(secondSphereNode)
        
        let thirdSphereGeometry = SCNSphere(radius: 1.5)
        thirdSphereGeometry.firstMaterial?.diffuse.contents = UIColor.redColor()
        let thirdSphereNode = SCNNode(geometry: thirdSphereGeometry)
        thirdSphereNode.position = SCNVector3(x: 0.0, y: 3.0, z: 0.0)
        self.rootNode.addChildNode(thirdSphereNode) */
        
        var geometries = [SCNSphere(radius: 1.0),
            SCNPlane(width: 1.0, height: 1.5),
            SCNBox(width: 1.0, height: 1.5, length: 2.0, chamferRadius: 0.0),
            SCNPyramid(width: 2.0, height: 1.5, length: 1.0),
            SCNCylinder(radius: 1.0, height: 1.5),
            SCNCone(topRadius: 0.5, bottomRadius: 1.0, height: 1.5),
            SCNTorus(ringRadius: 1.0, pipeRadius: 0.2),
            SCNTube(innerRadius: 0.5, outerRadius: 1.0, height: 1.5),
            SCNCapsule(capRadius: 0.5, height: 2.0)]
        
        /* var x:Float = 0.0
        for index in 0..<geometries.count {
            
            let hue:CGFloat = CGFloat(index) / CGFloat(geometries.count)
            let color = UIColor(hue: hue, saturation: 1.0, brightness: 1.0, alpha: 1.0)
            
            let geometry = geometries[index]
            geometry.firstMaterial?.diffuse.contents = color
            
            let node = SCNNode(geometry: geometry)
            node.position = SCNVector3(x: x, y: 0.0, z: 0.0)
            
            self.rootNode.addChildNode(node)
            
            x += 2.5
        } */
        
        var angle:Float = 0.0
        let radius:Float = 4.0
        let angleIncrement:Float = Float(M_PI) * 2.0 / Float(geometries.count)
        
        for index in 0..<geometries.count {
            
            let hue:CGFloat = CGFloat(index) / CGFloat(geometries.count)
            let color = UIColor(hue: hue, saturation: 1.0, brightness: 1.0, alpha: 1.0)
            
            let geometry = geometries[index]
            geometry.firstMaterial?.diffuse.contents = color
            
            let node = SCNNode(geometry: geometry)
            
            let x = radius * cos(angle)
            let z = radius * sin(angle)
            
            node.position = SCNVector3(x: x, y: 0, z: z)
            
            self.rootNode.addChildNode(node)
            
            angle += angleIncrement
            
            let sign:CGFloat = index % 2 == 0 ? 1.0 : -1.0
            let move1 = SCNAction.moveByX(0.0, y: sign * CGFloat(1.0), z: 0.0, duration: 1.0)
            let move2 = SCNAction.moveByX(0.0, y: sign * CGFloat(-1.0), z: 0.0, duration: 1.0)
            let sequence = SCNAction.sequence([move1,move2])
            let repeatedSequence = SCNAction.repeatActionForever(sequence)
            node.runAction(repeatedSequence)
        }
        
        func sinFunction(x: Float,z: Float) -> Float {
            let a = 0.2 * sin(x * 5 + z * 3) + 0.1
            let b = cos(x * 5 + z * 10 + 0.6) + 0.05
            let c = cos(x * x * z)
            return a * b * c
        }
        
        func squareFunction(x: Float,z: Float) -> Float {
            return x * x + z * z
        }
        
        let gridSize = 25
        
        let capsuleRadius:CGFloat = 1.0 / CGFloat(gridSize - 1)
        let capsuleHeight:CGFloat = capsuleRadius * 4.0
        
        var z:Float = Float(-gridSize + 1) * Float(capsuleRadius)
        
        for row in 0..<gridSize {
            var x:Float = Float(-gridSize + 1) * Float(capsuleRadius)
            for column in 0..<gridSize {
                let capsule = SCNCapsule(capRadius: capsuleRadius, height: capsuleHeight)
                
                let hue = CGFloat(abs(x * z))
                let color = UIColor(hue: hue, saturation: 1.0, brightness: 1.0, alpha: 1.0)
                
                capsule.firstMaterial?.diffuse.contents = color
                
                let capsuleNode = SCNNode(geometry: capsule)
                
                self.rootNode.addChildNode(capsuleNode)
                
                capsuleNode.position = SCNVector3Make(x, 0.0, z)
                
                let y = CGFloat(squareFunction(x,z: z))
                //let y = CGFloat(sinFunction(x, z: z))
                
                let moveUp = SCNAction.moveByX(0, y: y, z: 0, duration: 1.0)
                let moveDown = SCNAction.moveByX(0, y: -y, z: 0, duration: 1.0)
                
                let sequence = SCNAction.sequence([moveUp,moveDown])
                
                let repeatedSequence = SCNAction.repeatActionForever(sequence)
                
                capsuleNode.runAction(repeatedSequence)
                
                x += 2.0 * Float(capsuleRadius)
                
            }
            
            z += 2.0 * Float(capsuleRadius)
        }
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
