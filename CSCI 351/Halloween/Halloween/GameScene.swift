//
//  GameScene.swift
//  Halloween
//
//  Created by Sean Tesch on 10/11/15.
//  Copyright (c) 2015 Sean Tesch. All rights reserved.
//

import SpriteKit

import SpriteKit

class GameScene: SKScene {
    
    var sprite: SKSpriteNode?
    
    override func didMoveToView(view: SKView) {
        
        let myLabel = SKLabelNode(fontNamed:"Chalkduster")
        myLabel.text = "Happy Halloween!";
        myLabel.fontSize = 45;
        myLabel.position = CGPoint(x:CGRectGetMidX(self.frame), y:CGRectGetMidY(self.frame));
        
        self.addChild(myLabel)
        
        sprite = SKSpriteNode(imageNamed: "lantern")
        sprite!.xScale = 0.5
        sprite!.yScale = 0.5
        
        sprite!.position = CGPointMake(frame.width / 2, frame.height / 2)
        
        self.addChild(sprite!)
    }
    
    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        
        let touch:UITouch = touches.first as UITouch!
        
        let touchPosition = touch.locationInNode(self)
        
        let currentPosition = sprite!.position
        
        let angle = atan2(currentPosition.y - touchPosition.y, currentPosition.x - touchPosition.x)
        
        let rotateAction = SKAction.rotateToAngle(angle + CGFloat(M_PI*0.5), duration: 0.0)
        let moveAction = SKAction.moveTo(touchPosition, duration: 0.5)
                sprite!.runAction(SKAction.sequence([rotateAction, moveAction]))
        
    }
    
    override func update(currentTime: CFTimeInterval) {
        /* Called before each frame is rendered */
    }
}
//
