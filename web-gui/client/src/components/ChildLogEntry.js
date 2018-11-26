import React, { Component } from 'react';
import ArrowIcon from '@material-ui/icons/ArrowRightAlt';
import { connect } from 'react-redux';
import {selectLog} from '../actions/LogActions';

class LogEntry extends Component {
    styles = {
        entryInnerContainer: {
            display: "flex",
            padding:"5px",
            flexDirection:"row",
            flex:1,
        },
        entryDataLeftCell: {
            flex:2,
            paddingLeft: "10px",
            paddingRight: "10px",
            borderRight: "2px solid black",
            borderColor: "#85aef2",
            borderRadius: "2px",
            flexDirection: 'row',
            display:'flex'

        },
        entryDataMiddleCell: {
            paddingLeft: "10px",
            paddingRight: "10px",
            alignItems: "center",
            flexDirection: 'column',
            flex: 4,
        },
        entryDataRightCell: {
            paddingLeft: "10px",
            paddingRight: "10px",
            alignItems: "center",
            flexDirection: 'column',
        },
        label: {
            paddingBottom:'2px',
            color: '#AAAAAA',
            fontSize: '13px',
        },
        sourceDestContainer:{
            flex:2,
            display: 'flex',
            flexDirection: 'row',
            alignItems: 'center',
            justifyContent: 'center',
        },
        attribContainer:{
            alignItems: "center",
            flexDirection: 'column',
        }
    }
  getLeftCellStyle = () => {
    if(this.props.selectedLog == this.props.guid){
        return {...this.styles.entryDataLeftCell, borderColor:'red'};
    } else {
        return this.styles.entryDataLeftCell;
    }
  }
  getArrowIconStyle =()=>{
      if(this.props.selectedLog == this.props.guid){
          return {color: 'red'}
      } else {
          return {color: '#85aef2'}
      }
  }
  selectLog = () => {
    if(this.props.selectedLog==this.props.guid){
        this.props.selectLog(-1);
    } else {
        this.props.selectLog(this.props.guid);
    }
  }
  getLabelStyle = () => {
    if(this.props.selectedLog == this.props.guid){
        return {...this.styles.label,color:'red'};
    } else {
        return this.styles.label;
    }
}
  render() {
    return (
        <div name="entryInnerContainer" style={this.styles.entryInnerContainer} onClick={this.selectLog}>        
            <div name="time" style={this.getLeftCellStyle()}>
                <ArrowIcon style={this.getArrowIconStyle()}/>  
                <div style={this.styles.attribContainer}>
                    <div style={this.getLabelStyle()}>
                        Time Received
                    </div>
                    <div>
                        {this.props.time}
                    </div>
                </div>
            </div>
            <div name="sourceDestContainer" style={this.styles.sourceDestContainer}>
                <div name="sender" style={this.styles.entryDataMiddleCell}>
                    <div style={this.getLabelStyle()}>
                        Sender
                    </div>
                    <div>
                        {this.props.sender}
                    </div>
                </div>
                <div name="recipient" style={this.styles.entryDataRightCell}>
                    <div style={this.getLabelStyle()}>
                        Type
                    </div>
                    <div>
                        Response To Request
                    </div>
                </div>
            </div>
        </div>
    );
  }
}
const mapStateToProps = store =>{
    return {
        selectedLog: store.selectedLog.selectedLog
    };
}
export default connect(mapStateToProps, {selectLog})(LogEntry);
