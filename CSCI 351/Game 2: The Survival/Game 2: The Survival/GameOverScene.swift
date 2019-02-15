//
//  GameOverScene.swift
//  Game 2: The Survival
//
//  Created by Sean Tesch on 11/5/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import Foundation
import SpriteKit
import UIKit

class GameOverScene: SKScene {
    
    init(size: CGSize, won:Bool, currentScore: Int) {
        
        super.init(size: size)
        
        // 1
        backgroundColor = SKColor.whiteColor()
        
        // 2
        let defaults = NSUserDefaults.standardUserDefaults()
        let highScore = defaults.integerForKey("highscore")
        
        func activity(high: Int, curr: Int) {
            let currentViewController:UIViewController=UIApplication.sharedApplication().keyWindow!.rootViewController!
            let myShare = "I beat the old high score of: \(highScore) with a score of: \(currentScore)"
            let activityVC:UIActivityViewController=UIActivityViewController(activityItems: [myShare], applicationActivities: nil)
            currentViewController.presentViewController(activityVC, animated: true, completion: nil)
        }
        
        if currentScore > highScore {
            
            defaults.setInteger(currentScore, forKey: "highscore")
        
            activity(highScore, curr: currentScore)
            
        }
        
        let highScoreLabel = SKLabelNode(fontNamed: "Chalkduster")
        highScoreLabel.text = "The current high score is: \(String(highScore))"
        highScoreLabel.fontSize = 20
        highScoreLabel.fontColor = SKColor.blackColor()
        highScoreLabel.position = CGPoint(x: size.width/2, y: (size.height/2) + 80)
        addChild(highScoreLabel)
        
        let currScoreLabel = SKLabelNode(fontNamed: "Chalkduster")
        currScoreLabel.text = "Your score was: \(String(currentScore))"
        currScoreLabel.fontSize = 20
        currScoreLabel.fontColor = SKColor.blackColor()
        currScoreLabel.position = CGPoint(x: size.width/2, y: (size.height/2) + 40)
        addChild(currScoreLabel)
        
        let message = "Game Over"
        
        // 3
        let label = SKLabelNode(fontNamed: "Chalkduster")
        label.text = message
        label.fontSize = 35
        label.fontColor = SKColor.blackColor()
        label.position = CGPoint(x: size.width/2, y: size.height/2)
        addChild(label)
        
        // 4
        runAction(SKAction.sequence([
            SKAction.waitForDuration(5.0),
            SKAction.runBlock() {
                // 5
                let reveal = SKTransition.flipHorizontalWithDuration(0.5)
                let scene = GameScene(size: size)
                self.view?.presentScene(scene, transition:reveal)
            }
            ]))
        
    }
    
    // 6
    required init(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
